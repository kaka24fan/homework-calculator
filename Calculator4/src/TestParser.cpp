#include "TestParser.h"
#include "Parser.h"
#include "TreeEvaluator.h"

#include <fstream>
#include <iostream> // std::cout

#define CALC_INPUT_PATH "D:\\UNIVERSITY\\YEAR2\\Summer Work\\Calculator4\\Calculator4\\src\\calc_test_0.txt"
#define GRAMMAR_PATH "D:\\UNIVERSITY\\YEAR2\\Summer Work\\Calculator4\\Calculator4\\src\\GRAMMAR.txt"

void testParser()
{
	std::string input;
	std::ifstream infile(CALC_INPUT_PATH);
	std::getline(infile, input); // read in 1st line of the text file

	Lexer* lexer = new Lexer(input);
	Parser parser = Parser(GRAMMAR_PATH);

	Tree* parseTree = parser.parse(lexer);

	// TODO optional: Print the parse tree
	float result = final_eval(parseTree);

	std::cout << "\nRESULT: " << result << std::endl;
}
