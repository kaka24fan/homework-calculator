#pragma once

namespace Enums
{
	// having TokenName here causes duplicates with GrammarSymbol, but it's not needed here
	// cause it already is in Token class.
	// And I only put GrammarSymbol here to avoid a "#include" loop between Parser and something else...
	
	//enum TokenName { NUM, LEFTPAREN, RIGHTPAREN, DOT, PLUS, MINUS, MUL, FAC, COS, END };
	enum GrammarSymbol { NUM, LEFTPAREN, RIGHTPAREN, DOT, PLUS, MINUS, MUL, FAC, COS, END,
		START, E, F, I, F1, F2, F3, I1, I2, I3, INT, FLOAT };
	struct SymbolAndValue // value only used for symbol NUM.
	{					  // these things will be grow on the parse tree
		Enums::GrammarSymbol symbol;
		int ivalue;
		float fvalue;
	};
	//enum ActionType { ERROR, SHIFT, REDUCE, ACCEPT };
}