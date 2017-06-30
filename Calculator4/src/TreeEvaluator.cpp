#include "TreeEvaluator.h"

#include <cmath> // cos

Evaluation eval(Tree * t)
{
	// think this through...

	Enums::SymbolAndValue node = t->getPayload();
	switch (node.symbol)
	{
	case Enums::GrammarSymbol::NUM:
		return Evaluation{ node.ivalue, (float) node.ivalue, true }; // ?

	case Enums::GrammarSymbol::COS:
	}
}
