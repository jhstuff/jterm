#include "terminal.h"

namespace jtb
{


	std::string terminal::comp()
	{
		if(lines.empty())
			return "";	
		std::string temp;
		for(int i = 0; i<lines.size()-1; ++i)
			temp += lines[i].comp(fillLineTo);
		temp += lines.back().comp(fillLineTo,true);
		return temp;
	
	}
	void terminal::addLine(color * dFG, color * dBG, char * dA)
	{
		color defFG = defaultFG;
		color defBG = defaultBG;
		char defA = defaultAlpha;
		if(dFG)
			defFG = *dFG;
		if(dBG)
			defBG = *dBG;
		if(dA)
			defA = *dA;
		lines.emplace_back(); //new element
		lines.back().defaultFG = defFG; //set defaults
		lines.back().defaultBG = defBG;
		lines.back().defaultAlpha = defA;
		lines.back().endlChar = defaultEndlChar;
	}
	line * terminal::addLine(line * l)
	{
		if(!l)
			throw std::runtime_error("addLine");
		lines.push_back(*l); 
		return &lines.back();
	}
	void terminal::stringToLines(std::string s, int mode)
	{
		if(!mode)
			lines.clear();
		int i = 0;
		int k = 0;
		std::string temp;
		while(true)
		{
			k = i;
			i = s.find("\n",k+1);
			if(i==-1)
			{
				if(maxLineLength != -1)
				{
					for(;k<s.size(); k+=maxLineLength)
					{
						addLine();
						lines.back().setLine(s.substr(k,maxLineLength));
					}
					break;
				}
				addLine();
				lines.back().setLine(s.substr(k,-1));
				break;
			}
			if(i-k>maxLineLength && maxLineLength != -1)
			{
				addLine();
				lines.back().setLine(s.substr(k,maxLineLength));
				i = k + maxLineLength;
			}
			else
			{
				addLine();
				lines.back().setLine(s.substr(k,i-k));
			}
		}

	}
//outside class
	void terminalCopyTemplate(terminal * copyTo, terminal * toCopy)
	{
		if(!copyTo||!toCopy)
			throw std::runtime_error("terminalCopyTemplate");
		metaCpyTerminal(copyTo,toCopy);
	}

	terminal * newTerminal()
	{//factories in C++ lol
		return new terminal;
	}


}
