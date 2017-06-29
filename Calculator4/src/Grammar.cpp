#include "Grammar.h"

Grammar::Grammar(std::vector<Production> productions)
{
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

void Grammar::buildFirst()
{

}

void Grammar::buildFollow()
{

}
