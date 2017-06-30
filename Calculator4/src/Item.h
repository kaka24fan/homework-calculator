#pragma once
#include "Production.h"
#include "Enums.h"

#include <iostream> //cerr
class Item
{
public:
	Item(int pos, Production p);
	Item getAdvanced();
	int getDotPos();
	Production getProduction();
	Enums::GrammarSymbol symbolAfterDot();
	bool isTheNextSymbolThis(Enums::GrammarSymbol sym);
	bool isItemOver();
	inline bool operator< (const Item &i1) const
	{
		return (i1.dotPos != dotPos) || (i1.production < production);
	}
	inline bool operator== (const Item &i1) const
	{
		return !(*this < i1);
	}
private:
	int dotPos;
	Production production;
};