#include "ParseTree.h"

#include<iostream> // std::cerr

Tree::Tree(Enums::SymbolAndValue p)
{
	payload = p;
	children[0] = nullptr;
	children[1] = nullptr;
	children[2] = nullptr;
}

Tree::Tree(Enums::SymbolAndValue p, Tree* first)
{
	payload = p;
	children[0] = first;
	children[1] = nullptr;
	children[2] = nullptr;
}

Tree::Tree(Enums::SymbolAndValue p, Tree* first, Tree* second)
{
	payload = p;
	children[0] = first;
	children[1] = second;
	children[2] = nullptr;
}

Tree::Tree(Enums::SymbolAndValue p, Tree* first, Tree* second, Tree* third)
{
	payload = p;
	children[0] = first;
	children[1] = second;
	children[2] = third;
}

void Tree::addChild(Tree* child)
{
	if (!children[0])
		children[0] = child;
	else if (!children[1])
		children[1] = child;
	else if (!children[2])
		children[2] = child;
	std::cerr << "Can't add more children to tree node!\n";
	// else error
}

Tree** Tree::getChildren()
{
	return children;
}

Enums::SymbolAndValue Tree::getPayload()
{
	return payload;
}
