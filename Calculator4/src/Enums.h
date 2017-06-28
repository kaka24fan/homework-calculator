namespace Enums
{
	enum TokenName { NUM, LEFTPAREN, RIGHTPAREN, DOT, PLUS, MINUS, MUL, FAC, COS, END };
	enum GrammarSymbol { NUM, LEFTPAREN, RIGHTPAREN, DOT, PLUS, MINUS, MUL, FAC, COS, END /* , nonterminals... */ };
	enum ActionType { ERROR, SHIFT, REDUCE, ACCEPT };
}