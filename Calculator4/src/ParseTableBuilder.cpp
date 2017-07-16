#include "ParseTableBuilder.h"
#include "GrammarGetter.h"
#include "ItemSetOps.h"

ParseTableBuilder::ParseTableBuilder(std::string grammar_path)
	:
	grammar ( getGrammar(grammar_path) )
{
	// build the LR0 itemset collection:
	construct_LR0_items();

	std::cout << "\nLR0_items size: " << LR0_items.size() << "\n\n";
	for (int i = 0; i < LR0_items.size(); i++)
	{
		std::cout << "LR0 itemset #" << i << ":\n";
		std::cout << isetToString(LR0_items[i]) << "\n\n";
	}
}

//helper helper function:
bool equal(std::set<Item> s1, std::set<Item> s2)
{
	std::set<Item> s11 = s1;
	for (Item i : s2)
		s11.erase(i);
	if (!s11.empty())
		return false;

	std::set<Item> s22 = s2;
	for (Item i : s1)
		s22.erase(i);
	if (!s22.empty())
		return false;

	return true;
}

//helper function:
//we need itemset equality check
bool contains(std::vector< std::set<Item> > collection, std::set<Item> iset)
{
	for (std::set<Item> iset2 : collection)
	{
		if (equal(iset2, iset))
			return true;
	}
	return false;
}

void ParseTableBuilder::construct_LR0_items()
{
	std::vector< std::set<Item> > collection;
	std::vector< std::set<Item> > collection_buffer;
	std::vector<Production> productions = grammar.getProductions();

	collection.push_back(
		// S' -> S production is always the last one
		getClosure(
			std::set<Item> { Item(0, productions[productions.size() - 1]) },
			productions
		)
	);


	bool didSomething = true;
	while (didSomething)
	{
		collection_buffer.clear();
		didSomething = false;
		for (std::set<Item> i : collection)
		{
			// do it for all grammar symbols, so all terminals and all nonterminals
			for (Enums::GrammarSymbol sym : grammar.getTerminals())
			{
				std::set<Item> itemset = grammar.goTo(i, sym);
				std::cout << " " << itemset.empty() << contains(collection, itemset); // DEBUG
				if (!itemset.empty() && !contains(collection, itemset) && !contains(collection_buffer, itemset))
				{
					didSomething = true;
					collection_buffer.push_back(itemset);
				}
			}
			for (Enums::GrammarSymbol sym : grammar.getNonterminals())
			{
				std::set<Item> itemset = grammar.goTo(i, sym);
				std::cout << " " << itemset.empty() << contains(collection, itemset); // DEBUG
				if (!itemset.empty() && !contains(collection, itemset) && !contains(collection_buffer, itemset))
				{
					didSomething = true;
					collection_buffer.push_back(itemset);
				}
			}
		}
		for (auto x : collection_buffer)
			collection.push_back(x);
	}

	LR0_items = collection;
}

std::map<int, std::map<Enums::GrammarSymbol, Action>> ParseTableBuilder::build_action()
{
	std::map<int, std::map<Enums::GrammarSymbol, Action>> result;
	
	// initialize everything to error: (step 4 from the book)
	for (int i = 0; i < LR0_items.size(); i++)
	{
		for (Enums::GrammarSymbol sym : grammar.getNonterminals())
			result[i][sym] = Action(Action::ActionType::ERROR, -1, Production());
		for (Enums::GrammarSymbol sym : grammar.getTerminals())
			result[i][sym] = Action(Action::ActionType::ERROR, -1, Production());
		
		// all relevant symbols other than END should be matched by above two cases
		result[i][Enums::GrammarSymbol::END] = Action(Action::ActionType::ERROR, -1, Production());
	}

	// step 2a from the book
	for (int i = 0; i < LR0_items.size(); i++)
	{
		for (Item it : LR0_items[i])
		{
			if (it.isItemOver())
				continue;

			Enums::GrammarSymbol nextSym = it.symbolAfterDot();

			// if we already went thru this transition, continue
			if (result[i][nextSym].getType() != Action::ActionType::ERROR)
				continue;

			std::set<Item> destination = grammar.goTo(LR0_items[i], nextSym);

			//identify which state we just got to:
			int j = 0;
			for ( ; j < LR0_items.size(); j++)
			{
				if (equal(LR0_items[j], destination))
					break;
			}

			//this is just a dummy production and should never be accessed
			result[i][nextSym] = Action(Action::ActionType::SHIFT, j, Production());
		}
	}

	// steps 2b, 2c from the book
	for (int i = 0; i < LR0_items.size(); i++)
	{
		for (Item it : LR0_items[i])
		{
			if (it.isItemOver())
			{
				Enums::GrammarSymbol head = it.getProduction().getHead();
				if (head == Enums::GrammarSymbol::EXTENDED_START)
					result[i][Enums::GrammarSymbol::END] = Action(Action::ActionType::ACCEPT, -1, Production());
				else
				{
					for (Enums::GrammarSymbol sym : grammar.followOf(head))
						result[i][sym] = Action(Action::ActionType::REDUCE, -1, it.getProduction());
				}
			}
		}
	}

	// initial state will be 0

	return result;
}

std::map<int, std::map<Enums::GrammarSymbol, int>> ParseTableBuilder::build_go_to()
{
	std::map<int, std::map<Enums::GrammarSymbol, int>> result;

	// initialize everything to error: (step 4 from the book)
	for (int i = 0; i < LR0_items.size(); i++)
	{
		for (Enums::GrammarSymbol sym : grammar.getNonterminals())
			result[i][sym] = -1; // -1 represents error - will have to check for that
		for (Enums::GrammarSymbol sym : grammar.getTerminals())
			result[i][sym] = -1;

		result[i][Enums::GrammarSymbol::END] = -1; // all other relevant symbols should be matched by above
	}

	// step 3 from the book:
	for (Enums::GrammarSymbol sym : grammar.getNonterminals())
	{
		for (int i = 0; i < LR0_items.size(); i++)
		{
			std::set<Item> destination = grammar.goTo(LR0_items[i], sym);

			//identify which state we just got to:
			int j = 0;
			for (; j < LR0_items.size(); j++)
			{
				if (equal(LR0_items[j], destination))
					break;
			}

			if (j == LR0_items.size()) // means goTo returned empty set, not matched to any
				continue;

			result[i][sym] = j;
		}
	}

	return result;
}

