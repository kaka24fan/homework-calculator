#include "Grammar.h"
#include "ItemSetOps.h"

Grammar::Grammar(std::vector<Production> productions)
{
	this->productions = productions;
	startSymbol = productions[0].getHead();

	// extend the grammar - the S' -> S production is the last one now.
	this->productions.push_back(Production(
		std::vector<Enums::GrammarSymbol> {startSymbol},
		Enums::GrammarSymbol::EXTENDED_START
	));

	// identify terminals:
	for (Production p : productions)
	{
		nonterminals.insert(p.getHead());
		for (Enums::GrammarSymbol sym : p.getBodyCopy())
		{
			terminals.insert(sym);
		}
	}
	
	// set difference:
	for (Enums::GrammarSymbol sym : nonterminals)
	{
		terminals.erase(sym);
	}

	// Now the Grammar has the terminals and nonterminals and the start symbol stored.

	// construct 'first' table:
	buildFirst();
	// construct 'follow' table:
	buildFollow();
}

std::set<Enums::GrammarSymbol> Grammar::followOf(Enums::GrammarSymbol sym)
{
	return follow[sym];
}

std::set<Enums::GrammarSymbol> Grammar::firstOf(Enums::GrammarSymbol sym)
{
	return first[sym];
}

std::set<Enums::GrammarSymbol> Grammar::getTerminals()
{
	return terminals;
}

std::set<Enums::GrammarSymbol> Grammar::getNonterminals()
{
	return nonterminals;
}

std::vector<Production> Grammar::getProductions()
{
	return productions;
}

void Grammar::buildFirst() // by the book, except we don't use epsilon in our grammars
{
	// step 1 from book:
	for (Enums::GrammarSymbol terminal : terminals)
		first[terminal] = std::set<Enums::GrammarSymbol>{ terminal };
	
	// step 2 from book:
	bool didSomething = true;
	while (didSomething)
	{
		didSomething = false;
		for (Production p : productions)
		{
			int sizeBefore = first[p.getHead()].size();
			first[p.getHead()].insert(
				first[p.getBodyCopy()[0]].begin(),
				first[p.getBodyCopy()[0]].end()
			);
			if (first[p.getHead()].size() > sizeBefore)
				didSomething = true;
		}
	}

	// step 3 from book irrelevant as no epsilons appear in our grammars
}

void Grammar::buildFollow() // by the book, except we don't use epsilon in our grammars
{
	// step 1 from book:
	follow[startSymbol] = std::set<Enums::GrammarSymbol>{ Enums::GrammarSymbol::END };

	// step 2 from book:
	for (Production p : productions)
	{
		std::vector<Enums::GrammarSymbol> body = p.getBodyCopy();
		int bodySize = body.size();

		for (int i = 0; i < bodySize - 1; i++)
		{
			follow[body[i]].insert(
				first[body[i+1]].begin(),
				first[body[i+1]].end()
			);
		}
	}

	// step 3 from book:
	bool didSomething = true;
	while (didSomething)
	{
		didSomething = false;
		for (Production p : productions)
		{
			Enums::GrammarSymbol last = p.getBodyCopy()[p.getBodySize() - 1];
			int sizeBefore = first[last].size();
			first[last].insert(
				first[p.getHead()].begin(),
				first[p.getHead()].end()
			);
			if (first[last].size() > sizeBefore)
				didSomething = true;
		}
	}
}

std::set<Item> Grammar::goTo(std::set<Item> itemSet, Enums::GrammarSymbol sym)
{
	std::set<Item> res{};
	for (Item it : itemSet)
	{
		if (it.isTheNextSymbolThis(sym))
			res.insert(it.getAdvanced());
	}
	return getClosure(res);
}
