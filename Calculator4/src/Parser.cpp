#include "Parser.h"
#include "ParseTree.h"

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
		std::string act = action[state][sym.symbol];
		if (act[0] == 's') // action is shift t
		{
			int t = std::stoi(act.substr(1));
			stateStack.push(t);
			sym = readSymbol();
		}
		else if (act[0] == 'r') // TODO FIXME I really need to think this thru better!
		{ }
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
		return SymbolAndValue{ GrammarSymbol::LEFTPAREN, 0, 0.0 };
	case Token::TokenName::RIGHTPAREN:
		return SymbolAndValue{ GrammarSymbol::RIGHTPAREN, 0, 0.0 };
	case Token::TokenName::DOT:
		return SymbolAndValue{ GrammarSymbol::DOT, 0, 0.0 };
	case Token::TokenName::PLUS:
		return SymbolAndValue{ GrammarSymbol::PLUS, 0, 0.0 };
	case Token::TokenName::MINUS:
		return SymbolAndValue{ GrammarSymbol::MINUS, 0, 0.0 };
	case Token::TokenName::MUL:
		return SymbolAndValue{ GrammarSymbol::MUL, 0, 0.0 };
	case Token::TokenName::FAC:
		return SymbolAndValue{ GrammarSymbol::FAC, 0, 0.0 };
	case Token::TokenName::COS:
		return SymbolAndValue{ GrammarSymbol::COS, 0, 0.0 };
	case Token::TokenName::END:
		return SymbolAndValue{ GrammarSymbol::END, 0, 0.0 };
	case Token::TokenName::NUM:
		return SymbolAndValue{ GrammarSymbol::NUM, t->getVal(), 0.0 };
	}
}

Parser::SymbolAndValue Parser::readSymbol()
{
	return tokenToSymbol(lexer->get());
}
