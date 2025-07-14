#include "word.h"
namespace jtb
{

std::string word::comp(std::string force)
{
	std::string toPrint;
	if(force == "")
		toPrint=w;
	else
		toPrint=force;
	std::string temp = "";
	if(enableColor)
	{
		//ForeGround
		temp = "\033[38;2;";
		temp += std::to_string(int(FG.r)) + ";" + 
		  std::to_string(int(FG.g)) + ";" + std::to_string(int(FG.b)) + "m";
		//BackGround
		temp += "\033[48;2;";
		temp += std::to_string(int(BG.r)) + ";" + std::to_string(int(BG.g)) + ";" + std::to_string(int(BG.b)) + "m";
	}
	temp+=toPrint;
	if(enableColor)
	{//reset after
		temp += "\033[0m";
	}
	return temp;
}

}

