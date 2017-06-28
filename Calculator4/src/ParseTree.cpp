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

Tree::Tree()
{
	children[0] = nullptr;
	children[1] = nullptr;
	children[2] = nullptr;
}

Tree::Tree(Tree* first)
{
	children[0] = first;
	children[1] = nullptr;
	children[2] = nullptr;
}

Tree::Tree(Tree* first, Tree* second)
{
	children[0] = first;
	children[1] = second;
	children[2] = nullptr;
}

Tree::Tree(Tree* first, Tree* second, Tree* third)
{
	children[0] = first;
	children[1] = second;
	children[2] = third;
}

Tree** Tree::getChildren()
{
	return children;
}

T Tree::SymbolAndValue()
{
	return payload;
}
