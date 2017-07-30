#include "Production.h"

#include <iostream>

Production::Production(std::vector<Enums::GrammarSymbol> b, Enums::GrammarSymbol h)
{
	body = b;
	head = h;
}

int Production::getBodySize()
{
	return body.size();
}

Enums::GrammarSymbol Production::getHead()
{
	return head;
}

Production::Production(std::string s)
{
	body.clear();

	std::string buff = "";
	
	char separator = ' ';
	bool assignedHead = false;

	for (char c : s)
	{
		if (c != separator) 
			buff += c; 
		else if (c == separator && buff != "") 
		{ 
			if (assignedHead)
				body.push_back(Enums::stringToSymbol(buff));
			else
			{
				head = Enums::stringToSymbol(buff);
				assignedHead = true;
			}
			buff = "";
		}
	}
	if (buff != "")
	{
		if (assignedHead)
			body.push_back(Enums::stringToSymbol(buff));
		else
		{
			head = Enums::stringToSymbol(buff);
			assignedHead = true;
		}
	}

	if (!assignedHead)
	{
		//error:
		std::cerr << "Production constructor error: that"
				  << " production didn't even assign head...\n"
				  << "...The string was: " << s << " (length " << s.size() << ")\n";
	}
}

Production::Production()
{
}

std::vector<Enums::GrammarSymbol> Production::getBodyCopy()
{
	return body; // TODO make sure that gives a copy, not reference! I think it does...
}

std::string Production::toString()
{
	std::string res = Enums::symbolToString(head) + " -> ";
	for (Enums::GrammarSymbol sym : body)
		res += Enums::symbolToString(sym) + " ";
	return res;
}
