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

	inline bool operator < (const Item &i1) const
	{
		if (production < i1.production)
			return true;
		if (i1.production < production)
			return false;
		return dotPos < i1.dotPos;
	}

	inline bool operator == (const Item &i1) const
	{
		return !(*this < i1) && !(i1 < *this);
		/* should be equivalent to:
		return dotPos == i1.dotPos && production == i1.production;
		*/
	}

private:
	int dotPos;
	Production production;
};