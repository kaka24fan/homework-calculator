#pragma once
#include "Lexer.h"
#include "Action.h"
#include "Enums.h"
#include "ParseTree.h"

#include <stack>
#include <vector>
#include <map>
#include <string>

class Parser
{
public:
	Parser(std::string grammar_path);
	Tree* parse(Lexer* l);
	void restart();
private:
	std::stack<Tree*> treeStack;
	std::stack<int> stateStack;
	std::map< int, std::map< Enums::GrammarSymbol, Action > > action;
	std::map< int, std::map< Enums::GrammarSymbol, int > > go_to;

	Enums::SymbolAndValue tokenToSymbol(Token t);
	Enums::SymbolAndValue readSymbol(Lexer* l);
	void fail(std::string msg);
};