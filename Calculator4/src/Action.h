#pragma once
#include "Production.h"

class Action
{
public:
	enum ActionType { ERROR, SHIFT, REDUCE, ACCEPT };
	ActionType getType() { return type; }
	int getShiftState() { return val_shift; }
	Production getProduction() { return val_reduce; }
	Action(ActionType type, int val_shift, Production val_reduce);
	Action(); // default constructor, not gonna be used
private:
	ActionType type;
	int val_shift;
	Production val_reduce;
};