#include "TreeEvaluator.h"

#include <cmath> // cos

Evaluation eval(Tree * t)
{
	Enums::SymbolAndValue node = t->getPayload();
	float farg0, farg1, farg2;
	int iarg0, iarg1, iarg2;
	Evaluation arg0, arg1, arg2;

	switch (node.symbol)
	{

	case Enums::GrammarSymbol::NUM: // LEAF CASE aka RECURSION BASE
		return intEval(node.ivalue);

	case Enums::GrammarSymbol::COS:
		arg0 = eval(t->getChildren()[0]);
		farg0 = arg0.fval;
		return floatEval(cos(farg0));

	case Enums::GrammarSymbol::FAC:
		arg0 = eval(t->getChildren()[0]);
		iarg0 = arg0.ival;
		return intEval(factorial(iarg0));

	case Enums::GrammarSymbol::PLUS:
		arg0 = eval(t->getChildren()[0]);
		arg2 = eval(t->getChildren()[2]);
		if (arg0.itsAnInt)
		{
			iarg0 = arg0.ival;
			iarg2 = arg2.ival;
			return intEval(iarg0 + iarg2);
		}
		else
		{
			farg0 = arg0.fval;
			farg2 = arg2.fval;
			return floatEval(farg0 + farg2);
		}

	case Enums::GrammarSymbol::MUL:
		arg0 = eval(t->getChildren()[0]);
		arg2 = eval(t->getChildren()[2]);
		if (arg0.itsAnInt)
		{
			iarg0 = arg0.ival;
			iarg2 = arg2.ival;
			return intEval(iarg0 * iarg2);
		}
		else
		{
			farg0 = arg0.fval;
			farg2 = arg2.fval;
			return intEval(farg0 * farg2);
		}

	case Enums::GrammarSymbol::MINUS:
		arg0 = eval(t->getChildren()[0]);
		arg2 = eval(t->getChildren()[2]);
		if (arg0.itsAnInt)
		{
			iarg0 = arg0.ival;
			iarg2 = arg2.ival;
			return intEval(iarg0 - iarg2);
		}
		else
		{
			farg0 = arg0.fval;
			farg2 = arg2.fval;
			return intEval(farg0 - farg2);
		}

	case Enums::GrammarSymbol::INT:
		arg0 = eval(t->getChildren()[0]);
		return arg0;

	case Enums::GrammarSymbol::FLOAT:
		//case num.num
		if (t->getChildren()[2]) // ...is not null
		{
			arg0 = eval(t->getChildren()[0]);
			arg2 = eval(t->getChildren()[2]);
			farg0 = arg0.fval;
			farg2 = arg2.fval;
			return floatEval(farg0 + toFraction(farg2));
		}
		//case num.
		else if (t->getChildren()[1]->getPayload().symbol == Enums::GrammarSymbol::DOT)
		{
			arg0 = eval(t->getChildren()[0]);
			farg0 = arg0.fval;
			return floatEval(farg0);
		}
		//case .num
		else
		{
			arg0 = eval(t->getChildren()[0]);
			farg0 = arg0.fval;
			return floatEval(toFraction(farg0));
		}
		
	// keep going... case Enums::GrammarSymbol::
	}
}

Evaluation floatEval(float f)
{
	return Evaluation{ -69, f, false };
}

Evaluation intEval(int i)
{
	return Evaluation{ i, (float)i, true };
}

int factorial(int i)
{
	int r = 1;
	for (int j = 1; j < i; j++)
		r *= j;
	return r;
}

int toFraction(int t) // takes t and divides it by 10 until it's smaller than 1.
{
	float f = (float)t;
	while (f >= 1.0)
		f /= 10.0;
	return f;
}