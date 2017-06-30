#include "ParseTableBuilder.h"
#include "GrammarGetter.h"

ParseTableBuilder::ParseTableBuilder(std::string grammar_path)
	:
	grammar ( getGrammar(grammar_path) )
{

}

std::map<int, std::map<Enums::GrammarSymbol, int>> ParseTableBuilder::build_go_to()
{
	return std::map<int, std::map<Enums::GrammarSymbol, int>>();
}

std::map<int, std::map<Enums::GrammarSymbol, Action>> ParseTableBuilder::build_action()
{
	return std::map<int, std::map<Enums::GrammarSymbol, Action>>();
}
