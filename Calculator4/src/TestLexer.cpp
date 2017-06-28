#include "Lexer.h"

#include<iostream> // std::cin, std::cout
#include<conio.h> // getch

#include <string>
#include <fstream>

#define CALC_INPUT_PATH "D:\\UNIVERSITY\\YEAR2\\Summer Work\\Calculator4\\Calculator4\\src\\calc_test_0.txt"

void testLexer()
{
	std::string input;
	std::ifstream infile(CALC_INPUT_PATH);
	std::getline(infile, input); // read in 1st line of the text file

	Lexer lexer = *new Lexer(input);
	Token* t;
	for (t = lexer.get(); t->getName() != Token::TokenName::END; t = lexer.get())
	{
		std::cout << t->toString() << " ";
	}
	std::cout << t->toString() << " <- this last one should be (END)! ";

	getch();
}