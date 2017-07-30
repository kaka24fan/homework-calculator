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

		int beforeInsertionSize = s.size();

		s.insert(toBeAdded.begin(), toBeAdded.end()); // insert all

		if (s.size() == beforeInsertionSize)
			break; // nothing changed
	}

	return s;
}

std::string isetToString(std::set<Item> s)
{
	if (s.empty())
		return "EMPTY_ITEM_SET";
	std::string res = "";
	for (Item it : s)
	{
		res += it.toString() + "\n";
	}
	res.erase(res.end() - 1, res.end());
	return res;
}
