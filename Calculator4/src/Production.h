#pragma once
#include "Enums.h"

#include <vector>
#include <string>

class Production
{
public:
	Production(std::vector<Enums::GrammarSymbol> b, Enums::GrammarSymbol h);
	int getBodySize();
	Enums::GrammarSymbol getHead();
	Production fromString(std::string s);
private:
	std::vector<Enums::GrammarSymbol> body;
	Enums::GrammarSymbol head;
};