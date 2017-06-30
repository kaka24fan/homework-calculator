#include "ParseTableBuilder.h"
#include "GrammarGetter.h"
#include "ItemSetOps.h"

ParseTableBuilder::ParseTableBuilder(std::string grammar_path)
	:
	grammar ( getGrammar(grammar_path) )
{
	construct_LR0_items();
}

std::map<int, std::map<Enums::GrammarSymbol, int>> ParseTableBuilder::build_go_to()
{
	return std::map<int, std::map<Enums::GrammarSymbol, int>>();
}

std::map<int, std::map<Enums::GrammarSymbol, Action>> ParseTableBuilder::build_action()
{
	return std::map<int, std::map<Enums::GrammarSymbol, Action>>();
}


//helper helper function:
bool equal(std::set<Item> s1, std::set<Item> s2)
{
	std::set<Item> s11 = s1;
	for (Item i : s2)
		s11.erase(i);
	if (s11.empty())
		return false;

	std::set<Item> s22 = s2;
	for (Item i : s1)
		s2.erase(i);
	if (s22.empty())
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
	std::vector<Production> productions = grammar.getProductions();

	collection.push_back(
		// S' -> S production is always the last one
		getClosure(
			std::set<Item> { Item(0, productions[productions.size() - 1]) },
			grammar.getProductions()
		)
	);


	bool didSomething = true;
	while (didSomething)
	{
		didSomething = false;
		for (std::set<Item> i : collection)
		{
			// do it for all grammar symbols, so all terminals and all nonterminals
			for (Enums::GrammarSymbol sym : grammar.getTerminals())
			{
				std::set<Item> itemset = grammar.goTo(i, sym);
				if (!itemset.empty() && !contains(collection, itemset))
				{
					didSomething = true;
					collection.push_back(itemset);
				}
			}
			for (Enums::GrammarSymbol sym : grammar.getNonterminals())
			{
				std::set<Item> itemset = grammar.goTo(i, sym);
				if (!itemset.empty() && !contains(collection, itemset))
				{
					didSomething = true;
					collection.push_back(itemset);
				}
			}
		}
	}

	LR0_items = collection;
}
