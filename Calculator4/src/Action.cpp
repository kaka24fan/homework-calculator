#include "Action.h"

Action::Action(ActionType type, int val_shift, Production val_reduce)
	:
	type(type),
	val_shift(val_shift),
	val_reduce(val_reduce)
{
}

Action::Action() // default constructor, not gonna be used
	:
	val_reduce("")
{
	type = ActionType::ERROR;
	val_shift = 0;
}
