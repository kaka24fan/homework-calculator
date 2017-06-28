#include "Production.h"
class Action
{
public:
	enum ActionType { ERROR, SHIFT, REDUCE, ACCEPT };
	ActionType getType() { return type; }
	int getShiftState() { return val_shift; }
	Production getProduction() { return val_reduce; }
private:
	ActionType type;
	int val_shift;
	Production val_reduce;
};