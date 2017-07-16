#include "ParseTree.h"

#include<iostream> // std::cerr

Tree::Tree(Enums::SymbolAndValue p)
{
	children = new Tree* [3];
	payload = p;
	children[0] = nullptr;
	children[1] = nullptr;
	children[2] = nullptr;
}

Tree::Tree(Enums::SymbolAndValue p, Tree* first)
{
	children = new Tree*[3];
	payload = p;
	children[0] = first;
	children[1] = nullptr;
	children[2] = nullptr;
}

Tree::Tree(Enums::SymbolAndValue p, Tree* first, Tree* second)
{
	children = new Tree*[3];
	payload = p;
	children[0] = first;
	children[1] = second;
	children[2] = nullptr;
}

Tree::Tree(Enums::SymbolAndValue p, Tree* first, Tree* second, Tree* third)
{
	children = new Tree*[3];
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
	else
		// else error
		std::cerr << "Can't add more children to tree node!\n";
}

Tree** Tree::getChildren()
{
	return children;
}

Enums::SymbolAndValue Tree::getPayload()
{
	return payload;
}
