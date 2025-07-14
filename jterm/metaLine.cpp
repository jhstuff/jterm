#include "line.h"

namespace jtb
{


	void aLine(line * first, line * second)
	{ //Caution, no nullptr check, internal
		for(int i = 0; i<second->words.size(); ++i)
		{
			first->words.emplace_back();
			first->words.back() = second->words[i];
		}
	}
	void metaCpyLine(line * first, line * second)
	{ //Caution, no nullptr check, internal
		first->endlChar = second->endlChar;
		first->defaultFG = second->defaultFG;
		first->defaultBG = second->defaultBG;
		first->defaultAlpha = second->defaultAlpha;
	}

}
