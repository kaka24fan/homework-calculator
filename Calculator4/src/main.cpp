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
		if (line.at(0) == '#')
			continue;

		try
		{
			parser.restart();

			Lexer *lexer = new Lexer(line);

			Tree* parseTree = parser.parse(lexer);

			// print tree here

			float result = final_eval(parseTree);

			std::cout << "\n" << line << " = " << result;
		}
		catch (const std::exception& e)
		{

		}
	}

	while (std::cin >> line)
	{
		if (line.at(0) == 'q')
			break;

		try
		{
			parser.restart();

			Lexer *lexer = new Lexer(line);

			Tree* parseTree = parser.parse(lexer);

			// print tree here

			float result = final_eval(parseTree);

			std::cout << "\n" << line << " = " << result;
		}
		catch (const std::exception& e)
		{

		}
	}

	_getch();
	return 0;
}
