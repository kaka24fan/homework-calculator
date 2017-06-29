#pragma once
#include "Production.h"
#include "Enums.h"

#include <iostream> //cerr
class Item
{
public:
	Item(int pos, Production p);
	int getDotPos();
	Production getProduction();
	Enums::GrammarSymbol symbolAfterDot();
	bool isTheNextSymbolThis(Enums::GrammarSymbol sym);
	inline bool operator< (const Item &i1) const
	{
		return (i1.dotPos != dotPos) || (i1.production < production);
	}
private:
	int dotPos;
	Production production;
};