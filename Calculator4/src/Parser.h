#include "Lexer.h"
#include "Action.h"
#include "Enums.h"

#include <stack>
#include <vector>
#include <map>
#include <string>

class Parser
{
public:
	//enum GrammarSymbol { NUM, LEFTPAREN, RIGHTPAREN, DOT, PLUS, MINUS, MUL, FAC, COS, END /* , nonterminals... */ };
	Parser(Lexer* l);
	Tree* parse();
	struct SymbolAndValue // value only used for symbol NUM.
	{					  // these things will be grow on the parse tree
		Enums::GrammarSymbol symbol;
		int ivalue;
		float fvalue;
	};
private:
	Lexer* lexer;
	std::stack<SymbolAndValue> symStack;
	std::stack<int> stateStack;
	void shift();
	std::vector<int> num_values;
	SymbolAndValue tokenToSymbol(Token* t);
	std::map< int, std::map< Enums::GrammarSymbol, Action > > action;
	std::map< int, std::map< Enums::GrammarSymbol, int > > go_to;
	SymbolAndValue readSymbol();
	void fail(std::string msg);
};