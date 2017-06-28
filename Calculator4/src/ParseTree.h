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
	Tree* children[3];
	Parser::SymbolAndValue payload;
};