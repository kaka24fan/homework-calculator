#pragma once
#include "Enums.h"
#include "Production.h"

#include<map>
#include<set>
#include<vector>

class Grammar
{
public:
	Grammar(std::vector<Production> productions);
	std::set<Enums::GrammarSymbol> followOf(Enums::GrammarSymbol sym);
	std::set<Enums::GrammarSymbol> firstOf(Enums::GrammarSymbol sym);
private:
	std::set< Enums::GrammarSymbol> terminals; // needs to be populated in cons
	std::map< Enums::GrammarSymbol, std::set<Enums::GrammarSymbol> > first;
	std::map< Enums::GrammarSymbol, std::set<Enums::GrammarSymbol> > follow;
	void buildFirst();
	void buildFollow();
};