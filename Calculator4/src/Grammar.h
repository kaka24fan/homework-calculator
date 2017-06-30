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
	std::set< Enums::GrammarSymbol > followOf(Enums::GrammarSymbol sym);
	std::set< Enums::GrammarSymbol > firstOf(Enums::GrammarSymbol sym);
	std::set< Enums::GrammarSymbol > getTerminals();
	std::set< Enums::GrammarSymbol > getNonterminals();
private:
	std::vector<Production> productions;
	Enums::GrammarSymbol startSymbol;
	std::set< Enums::GrammarSymbol > terminals; // populated in the constructor
	std::set< Enums::GrammarSymbol > nonterminals; // populated in the constructor
	std::map< Enums::GrammarSymbol, std::set<Enums::GrammarSymbol> > first;
	std::map< Enums::GrammarSymbol, std::set<Enums::GrammarSymbol> > follow;
	void buildFirst();
	void buildFollow();
};