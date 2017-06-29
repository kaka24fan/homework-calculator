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
	Production(std::string s); // generates a production from 1-line text description
	std::vector<Enums::GrammarSymbol> getBodyCopy();

	// we overload < to work as != for purposes of storing these in sets
	inline bool operator< (const Production &p1) const
	{
		if (p1.head != head) return true;
		if (p1.body.size() != body.size()) return true;
		bool result = false;
		for (int i = 0; i < p1.body.size(); i++)
			if (p1.body[i] != body[i]) return true;
		return false;
	}
private:
	std::vector<Enums::GrammarSymbol> body;
	Enums::GrammarSymbol head;
};