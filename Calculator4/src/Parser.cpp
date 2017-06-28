#include "Parser.h"
#include "ParseTree.h"

#include<iostream> // std::cerr
#include<cstdlib>  // exit(int n)
#include<conio.h> // getch

void Parser::fail(std::string msg)
{
	std::cerr << "PARSER ERROR: " << msg;
	getch();
	exit(-69);
}

Parser::Parser(Lexer* l)
{
	lexer = l;
	stateStack.push(0);
}

Tree* Parser::parse() // page 251 in book
{
	SymbolAndValue sym = readSymbol();
	while (true)
	{
		int state = stateStack.top();
		Action act = action[state][sym.symbol];
		if (act.getType() == Action::ActionType::SHIFT) // action is shift t
		{
			int t = act.getShiftState();
			stateStack.push(t);
			sym = readSymbol();
		}
		else if (act.getType() == Action::ActionType::REDUCE) // TODO FIXME I really need to think this thru better!
		{ 
			Production p = act.getProduction();
			int s = p.getBodySize();
			for (int i = 0; i < s; i++)
			{
				stateStack.pop();
			}
			stateStack.push(go_to[state][p.getHead()]);
		}
		else if (act.getType() == Action::ActionType::ACCEPT) // TODO FIXME I really need to think this thru better!
		{
			break;
		}
		else // act.getType() == Action::ActionType::ERROR
		{
			fail("Action error");
		}
	}
}

void Parser::shift()
{
	Token* t = lexer->get();
	symStack.push(	tokenToSymbol(t) );
}

Parser::SymbolAndValue Parser::tokenToSymbol(Token* t)
{
	switch (t->getName())
	{
	case Token::TokenName::LEFTPAREN:
		return SymbolAndValue{ Enums::GrammarSymbol::LEFTPAREN, 0, 0.0 };
	case Token::TokenName::RIGHTPAREN:
		return SymbolAndValue{ Enums::GrammarSymbol::RIGHTPAREN, 0, 0.0 };
	case Token::TokenName::DOT:
		return SymbolAndValue{ Enums::GrammarSymbol::DOT, 0, 0.0 };
	case Token::TokenName::PLUS:
		return SymbolAndValue{ Enums::GrammarSymbol::PLUS, 0, 0.0 };
	case Token::TokenName::MINUS:
		return SymbolAndValue{ Enums::GrammarSymbol::MINUS, 0, 0.0 };
	case Token::TokenName::MUL:
		return SymbolAndValue{ Enums::GrammarSymbol::MUL, 0, 0.0 };
	case Token::TokenName::FAC:
		return SymbolAndValue{ Enums::GrammarSymbol::FAC, 0, 0.0 };
	case Token::TokenName::COS:
		return SymbolAndValue{ Enums::GrammarSymbol::COS, 0, 0.0 };
	case Token::TokenName::END:
		return SymbolAndValue{ Enums::GrammarSymbol::END, 0, 0.0 };
	case Token::TokenName::NUM:
		return SymbolAndValue{ Enums::GrammarSymbol::NUM, t->getVal(), 0.0 };
	}
}

Parser::SymbolAndValue Parser::readSymbol()
{
	return tokenToSymbol(lexer->get());
}
