#include "Enums.h"

#include <vector>

class Production
{
public:
	int getBodySize();
	Enums::GrammarSymbol getHead();
private:
	std::vector<Enums::GrammarSymbol> body;
	Enums::GrammarSymbol head;
};