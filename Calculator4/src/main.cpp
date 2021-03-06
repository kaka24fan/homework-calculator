#include "Lexer.h"
#include "Parser.h"
#include "TreeEvaluator.h"

#include<iostream> // std::cin, std::cout
#include<conio.h> // getch

#include <string>
#include <fstream>

#define CALC_INPUT_PATH "D:\\UNIVERSITY\\YEAR2\\Summer Work\\Calculator4\\Calculator4\\src\\input.txt"
#define GRAMMAR_PATH "D:\\UNIVERSITY\\YEAR2\\Summer Work\\Calculator4\\Calculator4\\src\\GRAMMAR.txt"

int main()
{
	std::ifstream input(CALC_INPUT_PATH);
	std::string line;
	
	Parser parser = Parser(GRAMMAR_PATH);
	
	while (std::getline(input, line))
	{
		if (line.length() == 0)
			continue;
		if (line.at(0) == '#')
			continue;
		if (line.at(0) == '/')
			break;

		try
		{
			parser.restart();

			Lexer *lexer = new Lexer(line);

			Tree* parseTree = parser.parse(lexer);

			// print tree here

			float result = final_eval(parseTree);

			std::cout << "\n" << line << " = " << result << "\n";
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << "\n";
		}
	}

	std::cout << "\nYou can input extra lines now, if you wish!\n";
	std::cout << "Close the console with \"q\"\n\n";

	while (std::getline(std::cin, line))
	{
		if (line.length() == 0)
			continue;

		if (line.at(0) == 'q')
			break;

		try
		{
			parser.restart();

			Lexer *lexer = new Lexer(line);

			Tree* parseTree = parser.parse(lexer);

			// print tree here

			float result = final_eval(parseTree);

			std::cout << "\n" << line << " = " << result << "\n\n";
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << "\n";
		}
	}

	return 0;
}
