#ifndef JTBTERMINAL
#define JTBTERMINAL

#include "line.h"
#include "word.h"

//definitions in terminal.cpp and metaTerminal.cpp
namespace jtb
{
	struct line;
	struct terminal
	{
		color defaultFG = {255,255,255};
		color defaultBG = {0,0,0};
		char defaultAlpha = 0;
		std::string defaultEndlChar = "\n";

		std::vector<line> lines;
		int fillLineTo = 0;
		int maxLineLength = -1;

		std::string comp();
		void addLine(color * dFG = nullptr, color * dBG = nullptr, char * dA = nullptr);
		line * addLine(line * l);
		void stringToLines(std::string s, int mode = 1);
	};

	void metaCpyTerminal(terminal * first, terminal * second); //meta
	void terminalCopyTemplate(terminal * copyTo, terminal * toCopy);
	terminal * newTerminal();
	
	
}
#endif
