#pragma once

#include<string>
#include<iostream> //cerr

namespace Enums
{
	/* having TokenName here causes duplicates with GrammarSymbol, but it's not needed here
	/  cause it already is in Token class.
	/  And I only put GrammarSymbol here to avoid a "#include" loop between Parser and something else...
	/
	/  PS
	/  Perhaps it was just the lack of #pragma once causing error - but I guess it can stay here
    */

	enum GrammarSymbol { NUM, LEFTPAREN, RIGHTPAREN, DOT, PLUS, MINUS, MUL, FAC, COS,
		START, E, F, I, F1, F2, F3, F4, I1, I2, I3, INT, FLOAT,
		END, EPSILON, EXTENDED_START }; // END corresponds to $ sign in the book

	struct SymbolAndValue // value only used for symbol NUM.
	{					  // these things will grow on the parse tree
		Enums::GrammarSymbol symbol;
		int ivalue;
		float fvalue;
	};

	inline std::string symbolToString(GrammarSymbol sym)
	{
		int index = sym;
		char* lookup[25] = { "NUM", "LEFTPAREN", "RIGHTPAREN", "DOT", "PLUS", "MINUS", "MUL", "FAC", "COS", "START", "E", "F", "I", "F1", "F2", "F3", "F4", "I1", "I2", "I3", "INT", "FLOAT", "END", "EPSILON", "EXTENDED_START" };
		return std::string(lookup[index]);
	}

	inline GrammarSymbol stringToSymbol(std::string s)
	{
		if (s == "START")
			return Enums::GrammarSymbol::START;
		if (s == "EXTENDED_START")
			return Enums::GrammarSymbol::EXTENDED_START;
		if (s == "E")
			return Enums::GrammarSymbol::E;
		if (s == "F")
			return Enums::GrammarSymbol::F;
		if (s == "F1")
			return Enums::GrammarSymbol::F1;
		if (s == "F2")
			return Enums::GrammarSymbol::F2;
		if (s == "F3")
			return Enums::GrammarSymbol::F3;
		if (s == "F4")
			return Enums::GrammarSymbol::F4;
		if (s == "I")
			return Enums::GrammarSymbol::I;
		if (s == "I1")
			return Enums::GrammarSymbol::I1;
		if (s == "I2")
			return Enums::GrammarSymbol::I2;
		if (s == "I3")
			return Enums::GrammarSymbol::I3;
		if (s == "INT")
			return Enums::GrammarSymbol::INT;
		if (s == "FLOAT")
			return Enums::GrammarSymbol::FLOAT;

		if (s == "+")
			return Enums::GrammarSymbol::PLUS;
		if (s == "-")
			return Enums::GrammarSymbol::MINUS;
		if (s == "*")
			return Enums::GrammarSymbol::MUL;
		if (s == "!")
			return Enums::GrammarSymbol::FAC;
		if (s == "(")
			return Enums::GrammarSymbol::LEFTPAREN;
		if (s == ")")
			return Enums::GrammarSymbol::RIGHTPAREN;
		if (s == ".")
			return Enums::GrammarSymbol::DOT;
		if (s == "cos")
			return Enums::GrammarSymbol::COS;
		if (s == "num")
			return Enums::GrammarSymbol::NUM;

		//error:
		std::cerr << "Can't read that grammar symbol: \'" << s << "\'\n";
		return Enums::GrammarSymbol::START;
	}
}