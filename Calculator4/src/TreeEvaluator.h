#pragma once
#include "ParseTree.h"
#include "Enums.h"

struct Evaluation
{
	int ival;
	float fval;
	bool itsAnInt;
};

float final_eval(Tree* t);
