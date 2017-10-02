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
	//this enum moved to Enums.h to avoid "#include" cycle with ParseTree
	//enum GrammarSymbol { NUM, LEFTPAREN, RIGHTPAREN, DOT, PLUS, MINUS, MUL, FAC, COS, END /* , nonterminals... */ };
	Parser(std::string grammar_path);
	Tree* parse(Lexer* l);
	/*struct SymbolAndValue // value only used for symbol NUM.
	{					  // these things will be grow on the parse tree
		Enums::GrammarSymbol symbol;
		int ivalue;
		float fvalue;
	};*/
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