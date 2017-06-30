#pragma once
#include "Enums.h"
#include "Production.h"
#include "Action.h"
#include "Grammar.h"

#include<map>
#include<vector>
#include<string>

class ParseTableBuilder
{
public:
	ParseTableBuilder(std::string grammar_path);
	std::map< int, std::map< Enums::GrammarSymbol, int > > build_go_to();
	std::map< int, std::map< Enums::GrammarSymbol, Action > > build_action();
private:
	Grammar grammar;
};