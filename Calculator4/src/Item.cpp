#include "Item.h"

Item::Item(int pos, Production p)
	:
	dotPos (pos),
	production (p)
{ }

int Item::getDotPos()
{
	return dotPos;
}

Production Item::getProduction()
{
	return production;
}

Enums::GrammarSymbol Item::symbolAfterDot()
{
	if (dotPos == production.getBodySize())
		return Enums::GrammarSymbol::EPSILON; // TODO is this a good idea?
	else if (dotPos < production.getBodySize())
		return production.getBodyCopy()[dotPos];
	else
	{
		std::cerr << "Item error: Production body access out of bounds!\n";
		return Enums::GrammarSymbol::START;
	}
}

bool Item::isTheNextSymbolThis(Enums::GrammarSymbol sym)
{
	return symbolAfterDot() == sym;
}
