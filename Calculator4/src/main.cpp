#include "Lexer.h"
#include "TestLexer.h"
#include "TestParser.h"

#include<iostream> // std::cin, std::cout
#include<conio.h> // getch

#include <string>
#include <fstream>

int main()
{
	std::cout << "\nLEXER SAYS:\n\n";
	testLexer();

	std::cout << "\n........................................................";
	std::cout << "\n\nPARSER SAYS:\n\n";
	testParser();

	_getch();
	return 0;
}
