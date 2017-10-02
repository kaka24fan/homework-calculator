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
	Production(); // dummy production
	std::vector<Enums::GrammarSymbol> getBodyCopy();

	// we overload < to work as != for purposes of storing these in sets
	inline bool operator < (const Production &p1) const
	{
		if (head < p1.head) return true;
		if (head > p1.head) return false;

		for (int i = 0; i < p1.body.size() && i < body.size(); i++)
		{
			if (body[i] < p1.body[i]) return true;
			if (body[i] > p1.body[i]) return false;
		}

		return (body.size() < p1.body.size()); // so false if they're equal
	}	
	
	inline bool operator == (const Production &p1) const
	{
		return !(*this < p1) && !(p1 < *this);
	}

	std::string toString();
private:
	std::vector<Enums::GrammarSymbol> body;
	Enums::GrammarSymbol head;
};