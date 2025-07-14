#ifndef JTERMWORD
#define JTERMWORD
#include <stdexcept>
#include <string>
#include <vector>
namespace jtb
{
	struct color
	{
		unsigned char r,g,b;
	};
	struct word
	{
		std::string w;
		color FG;
		color BG;
		char alpha;
		char enableColor = 0;
		std::string comp(std::string force = "");
	};
}
#endif
