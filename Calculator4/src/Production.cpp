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
				body.push_back(stringToSymbol(buff));
			else
			{
				head = stringToSymbol(buff);
				assignedHead = true;
			}
			buff = "";
		}
	}
	if (buff != "")
	{
		if (assignedHead)
			body.push_back(stringToSymbol(buff));
		else
			head = stringToSymbol(buff);
	}

	if (!assignedHead)
	{
		//error:
		std::cerr << "Production constructor error: that"
				  << " production didn't even assign head.\n";
	}
}


Enums::GrammarSymbol stringToSymbol(std::string s)
{
	if (s == "START" || s == "S")
		return Enums::GrammarSymbol::START;
	if (s == "E")
		return Enums::GrammarSymbol::E;
	if (s == "F")
		return Enums::GrammarSymbol::F;
	if (s == "F1")
		return Enums::GrammarSymbol::F1;
	if (s == "F2")
		return Enums::GrammarSymbol::F2;
	if (s == "F3")
		return Enums::GrammarSymbol::F3;
	if(s == "I")
		return Enums::GrammarSymbol::I;
	if(s == "I1")
		return Enums::GrammarSymbol::I1;
	if(s == "I2")
		return Enums::GrammarSymbol::I2;
	if (s == "I3")
		return Enums::GrammarSymbol::I3;
	if (s == "INT")
		return Enums::GrammarSymbol::INT;
	if (s == "FLOAT")
		return Enums::GrammarSymbol::FLOAT;

	if (s == "+")
		return Enums::GrammarSymbol::PLUS;
	if (s == "-")
		return Enums::GrammarSymbol::MINUS;
	if (s == "*")
		return Enums::GrammarSymbol::MUL;
	if (s == "!")
		return Enums::GrammarSymbol::FAC;
	if (s == "(")
		return Enums::GrammarSymbol::LEFTPAREN;
	if (s == ")")
		return Enums::GrammarSymbol::RIGHTPAREN;
	if (s == ".")
		return Enums::GrammarSymbol::DOT;
	if (s == "cos")
		return Enums::GrammarSymbol::COS;

	//error:
	std::cerr << "Can't read that production.\n";
	return Enums::GrammarSymbol::START;
}