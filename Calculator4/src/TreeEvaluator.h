#pragma once
#include "ParseTree.h"
#include "Enums.h"

struct Evaluation
{
	int ival;
	float fval;
	bool itsAnInt;
};

Evaluation eval(Tree* t);
