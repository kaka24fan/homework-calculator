#include "Parser.h"
#include "ParseTableBuilder.h"

#include<iostream> // std::cerr
#include<cstdlib>  // exit(int n)
#include<conio.h> // getch


void Parser::fail(std::string msg)
{
	throw std::exception(("\nPARSER ERROR: " + msg).c_str());
}

Parser::Parser(std::string grammar_path)
{
	stateStack.push(0);

	ParseTableBuilder ptb = ParseTableBuilder(grammar_path);
	action = ptb.build_action();
	go_to = ptb.build_go_to();
}

Tree* Parser::parse(Lexer* l) // page 251 in book
{
	Enums::SymbolAndValue sym = readSymbol(l);
	while (true)
	{
		int state = stateStack.top();
		Action act = action[state][sym.symbol];

		if (act.getType() == Action::ActionType::SHIFT) // action is shift t
		{
			int t = act.getShiftState();
			treeStack.push(new Tree(sym));
			stateStack.push(t);
			sym = readSymbol(l);
		}
		else if (act.getType() == Action::ActionType::REDUCE) // action is reduce p
		{ 
			Production p = act.getProduction();
			int s = p.getBodySize();
			std::stack<Tree*> children; // used temp-ly to build the tree node
			for (int i = 0; i < s; i++)
			{
				children.push( treeStack.top() );
				treeStack.pop();
				stateStack.pop();
			}
			
			//build tree node:
			Tree* t = new Tree(
				Enums::SymbolAndValue{ p.getHead(), 0, 0.0 }
				);

			while (!children.empty())
			{
				t->addChild(children.top());
				children.pop();
			}

			//push the new node:
			treeStack.push(t);
			
			//push the new state:
			int new_state = go_to[stateStack.top()][p.getHead()];
			if (new_state == -1) // error code
				fail("The go_to table read a -1.");
			stateStack.push(new_state);
		}
		else if (act.getType() == Action::ActionType::ACCEPT) // action is accept
		{
			break;
		}
		else // action is error
		{
			fail("Action read is ERROR");
		}
	}
	return treeStack.top();
}

void Parser::restart()
{
	treeStack = std::stack<Tree*> ();
	stateStack = std::stack<int> ();
	stateStack.push(0);
}

Enums::SymbolAndValue Parser::tokenToSymbol(Token t)
{
	switch (t.getName())
	{
	case Token::TokenName::LEFTPAREN:
		return Enums::SymbolAndValue{ Enums::GrammarSymbol::LEFTPAREN, 0, 0.0 };
	case Token::TokenName::RIGHTPAREN:
		return Enums::SymbolAndValue{ Enums::GrammarSymbol::RIGHTPAREN, 0, 0.0 };
	case Token::TokenName::DOT:
		return Enums::SymbolAndValue{ Enums::GrammarSymbol::DOT, 0, 0.0 };
	case Token::TokenName::PLUS:
		return Enums::SymbolAndValue{ Enums::GrammarSymbol::PLUS, 0, 0.0 };
	case Token::TokenName::MINUS:
		return Enums::SymbolAndValue{ Enums::GrammarSymbol::MINUS, 0, 0.0 };
	case Token::TokenName::MUL:
		return Enums::SymbolAndValue{ Enums::GrammarSymbol::MUL, 0, 0.0 };
	case Token::TokenName::FAC:
		return Enums::SymbolAndValue{ Enums::GrammarSymbol::FAC, 0, 0.0 };
	case Token::TokenName::COS:
		return Enums::SymbolAndValue{ Enums::GrammarSymbol::COS, 0, 0.0 };
	case Token::TokenName::END:
		return Enums::SymbolAndValue{ Enums::GrammarSymbol::END, 0, 0.0 };
	case Token::TokenName::NUM:
		return Enums::SymbolAndValue{ Enums::GrammarSymbol::NUM, t.getVal(), 0.0 };
	}
}

Enums::SymbolAndValue Parser::readSymbol(Lexer* l)
{
	return tokenToSymbol(l->get());
}
