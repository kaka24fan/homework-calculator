#include "ParseTree.h"

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

Parser::SymbolAndValue Tree::getPayload()
{
	return payload;
}
