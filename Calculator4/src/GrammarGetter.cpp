#include "GrammarGetter.h"

#include <fstream>
#include <string>

std::vector<Production> getGrammar(std::string path)
{
	std::vector<Production> grammar;

	std::ifstream infile(path);
	std::string line;

	while (std::getline(infile, line))
	{
		if (line.size > 0)
			grammar.push_back(Production(line));
	}

	return grammar;
}
