#include "Parser.h"

class Tree
{
public:
	Parser::SymbolAndValue getPayload();
	Tree** getChildren();
	Tree();
	Tree(Tree* first);
	Tree(Tree* first, Tree* second);
	Tree(Tree* first, Tree* second, Tree* third);
private:
	Tree* children[3]; // Number 3 dictated by the grammar I intend to use
	                   // It's equal to max production-body length
	Parser::SymbolAndValue payload;
};