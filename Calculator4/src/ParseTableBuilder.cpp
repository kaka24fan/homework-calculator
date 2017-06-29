#include "ParseTableBuilder.h"

ParseTableBuilder::ParseTableBuilder(std::string gp)
{
	grammar_path = gp;
}

std::map<int, std::map<Enums::GrammarSymbol, int>> ParseTableBuilder::build_go_to()
{
	
}

std::map<int, std::map<Enums::GrammarSymbol, Action>> ParseTableBuilder::build_action()
{
	
}
