#include <map>
#include "misc.h"

namespace jtb
{

	struct key
	{
		std::string key;
		unsigned long long bits;
		std::string keycode;
	};
	struct keyConfig
	{
		std::map<long long, key> config;
		void init(std::string filename = "");
	};

	unsigned long long keycodeToBits(std::string code);
	std::string keycodeToKey(std::string code);
	std::string bitsToString(unsigned long long b);

}
