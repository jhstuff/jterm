#include "line.h"

namespace jtb
{

	void line::setLine(std::string s)
	{
		words.clear();
		for(int i = 0; i<s.size(); ++i)
		{
			words.emplace_back();
			words[i].w = s[i];
			words[i].FG = defaultFG;
			words[i].BG = defaultBG;
			words[i].alpha = defaultAlpha;
		}

	}
	line * line::operator = (line x)
	{
		words.clear();
		aLine(this,&x);
		metaCpyLine(this,&x);
		return this;
	}
	line * line::operator += (line x)
	{
		aLine(this,&x);
		metaCpyLine(this,&x);
		return this;
	}
	int line::wordsSize()
	{
		int temp = 0;
		for(int i = 0; i<words.size(); ++i)
			temp+=words[i].w.size();
		return temp;
	}
	word * line::addWord(word * w)
	{
		if(!w)
			throw std::runtime_error("addWord");
		words.push_back(*w);
		return &words.back();	
	}


	std::string line::comp(int fillLineTo, bool noEndl)
	{
		if(words.empty())
			return "";
		std::string temp = words[0].comp();
		for(int i = 1; i<words.size(); ++i)
			temp += words[i].comp();
		//std::cout<<temp.size()<<" "<<fillLineTo<<" "
		if(fillLineTo)	
			for(int i = 0; i<fillLineTo-wordsSize(); ++i)
				temp+=" ";
		if(!noEndl)
			temp+=endlChar;
		return temp;
	}
//outside class
	line operator + (line x, line y)
	{
		return combineLine(&x,&y,nullptr);
	}
	void copyLine(line * copyTo, line * toCopy)
	{
		if(!copyTo||!toCopy)
			throw std::runtime_error("copyLine");
		metaCpyLine(copyTo,toCopy);
		copyTo->words.clear();
		aLine(copyTo,toCopy);	
	}
	void lineCopyTemplate(line * copyTo, line * toCopy)
	{
		if(!copyTo||!toCopy)
			throw std::runtime_error("lineCopyTemplate");
		metaCpyLine(copyTo, toCopy);
	}
	line combineLine(line * first, line * second, line * defaultTemplate)
	{
		if(!first||!second)
			throw std::runtime_error("combineLine");
		if(!defaultTemplate)
			defaultTemplate = first;
		line temp;
		aLine(&temp,first);
		aLine(&temp,second);
		metaCpyLine(&temp,defaultTemplate);	
		return temp;
	}
	void appendLine(line * appendTo, line * appendWith)
	{
		if(!appendTo||!appendWith)
			throw std::runtime_error("appendLine");
		aLine(appendTo, appendWith);
	}
	
	line makeLine(std::string content, terminal * terminalTemplate, color * FG, color * BG, char * A)
	{
		terminal * tempTerm = newTerminal();
		if(terminalTemplate)
			terminalCopyTemplate(tempTerm, terminalTemplate);	
		line temp;
		return temp;
	}




}
