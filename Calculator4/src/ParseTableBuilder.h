#pragma once

#include "Enums.h"
#include "Production.h"
#include "Action.h"
#include "Grammar.h"
#include "Item.h"

#include<map>
#include<vector>
#include<string>
#include<set>

class ParseTableBuilder
{
public:
	ParseTableBuilder(std::string grammar_path);
	std::map< int, std::map< Enums::GrammarSymbol, int > > build_go_to();
	std::map< int, std::map< Enums::GrammarSymbol, Action > > build_action();
private:
	Grammar grammar;
	std::vector< std::set<Item> > LR0_items;
	void construct_LR0_items();
};