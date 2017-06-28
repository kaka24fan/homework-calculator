#include "Production.h"

int Production::getBodySize()
{
	return body.size();
}

Enums::GrammarSymbol Production::getHead()
{
	return head;
}
