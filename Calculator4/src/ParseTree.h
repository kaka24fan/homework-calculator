#pragma once
#include "Enums.h"

class Tree
{
public:
	Enums::SymbolAndValue getPayload();
	Tree** getChildren();
	Tree(Enums::SymbolAndValue p);
	Tree(Enums::SymbolAndValue p, Tree* first);
	Tree(Enums::SymbolAndValue p, Tree* first, Tree* second);
	Tree(Enums::SymbolAndValue p, Tree* first, Tree* second, Tree* third);
	void addChild(Tree* child);
private:
	Tree* children[3]; // Number 3 dictated by the grammar I intend to use
	                   // It's equal to max production-body length
	Enums::SymbolAndValue payload;
};