#ifndef JTERMLINE
#define JTERMLINE
#include "terminal.h"
#include "word.h"


//definitions in line.cpp and metaLine.cpp
namespace jtb
{
	struct terminal;
	void terminalCopyTemplate(terminal * copyTo, terminal * toCopy);
	terminal * newTerminal();

	struct line;
	void aLine(line * first, line * second);
	void metaCpyLine(line * first, line * second);
	line combineLine(line * first, line * second, line * defaultTemplate);

	struct line
	{
		std::vector<word> words;
		std::string endlChar="\n";
		color defaultFG;
		color defaultBG;
		char defaultAlpha;
		void setLine(std::string s);
		line * operator = (line x);
		line * operator += (line x);
		int wordsSize();
		word * addWord(word * w);
		std::string comp(int fillLineTo = 0, bool noEndl = false);
	};

	//outside class
	line operator + (line x, line y);
	void aLine(line * first, line * second); //Caution, no nullptr check, internal
	void metaCpyLine(line * first, line * second); //Caution, no nullptr check, internal
	void copyLine(line * copyTo, line * toCopy);
	void lineCopyTemplate(line * copyTo, line * toCopy);
	line combineLine(line * first, line * second, line * defaultTemplate = nullptr);
	void appendLine(line * appendTo, line * appendWith);
	line makeLine(std::string content, terminal * terminalTemplate = nullptr, color * FG = nullptr, color * BG = nullptr, char * A = nullptr);

}
#endif
