#include "ItemSetOps.h"
#include "Enums.h"

std::set<Item> getClosure(std::set<Item> s, std::vector<Production> prods)
{
	std::set<Item> toBeAdded;

	while (true)
	{
		toBeAdded.clear();
		for (Item it : s)
		{
			Enums::GrammarSymbol next = it.symbolAfterDot();
			for (Production p : prods)
			{
				if (p.getHead() == next)
				{
					toBeAdded.insert(Item(0, p));
				}
			}
		}
		if (toBeAdded.size() == 0)
			break;

		s.insert(toBeAdded.begin(), toBeAdded.end()); // insert all
	}

	return s;
}
