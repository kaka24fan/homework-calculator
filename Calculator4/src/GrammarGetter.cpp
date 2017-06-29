#include "GrammarGetter.h"

#include <fstream>
#include <string>

Grammar getGrammar(std::string path)
{
	std::vector<Production> productions;

	std::ifstream infile(path);
	std::string line;

	while (std::getline(infile, line))
	{
		if (line.size > 0)
			productions.push_back(Production(line));
	}

	return Grammar(productions);
}
