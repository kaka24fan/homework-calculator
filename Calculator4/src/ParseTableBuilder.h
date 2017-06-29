#pragma once
#include "Enums.h"
#include "Production.h"
#include "Action.h"

#include<map>
#include<vector>

class ParseTableBuilder
{
public:
	ParseTableBuilder(std::string gp);
	std::map< int, std::map< Enums::GrammarSymbol, int > > build_go_to();
	std::map< int, std::map< Enums::GrammarSymbol, Action > > build_action();
private:
	std::vector< Production > grammar;
	std::string grammar_path;
};