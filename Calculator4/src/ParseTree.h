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
	Tree** children; // to have length 3
	Enums::SymbolAndValue payload;
};