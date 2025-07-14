#include "terminal.h"

namespace jtb
{

	void metaCpyTerminal(terminal * first, terminal * second)
	{ //Caution, no nullptr check, internal
		first->defaultFG = second->defaultFG;
		first->defaultBG = second->defaultBG;
		first->defaultAlpha = second->defaultAlpha;
		first->defaultEndlChar = second->defaultEndlChar;
		first->fillLineTo = second->fillLineTo;
		first->maxLineLength = second->maxLineLength;
	}

}
