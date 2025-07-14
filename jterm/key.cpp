#include "key.h"

namespace jtb
{

//keyConfig
	void keyConfig::init(std::string filename)
	{
		key temp;
		for(int i = 32; i<256; ++i)
		{
			temp.keycode = char(i);
			temp.key = char(i);
			temp.bits = char(i);
			config[temp.bits] = temp;	
		}
		if(filename != "")
		{
			std::string file = readFile(filename);
			std::string line;
			key k;
			for(std::string::size_type n = 0; n!=std::string::npos;
			 n = file.find('\n',n+1))
			{
				line = file.substr(n, file.find('\n',n+1) - n);
				std::cout<<line<<" ";
				if(line.find(':') == std::string::npos)
					continue;
				k.key = line.substr(0, line.find(":"));
				std::cout<<k.key<<" ";
				k.keycode = line.substr(line.find(":")+1);
				std::cout<<k.keycode<<" ";
				k.bits = keycodeToBits(k.keycode);
				std::cout<<k.bits<<"\n";
			}
		}
	}
//outside structs
 
	unsigned long long keycodeToBits(std::string code)
	{
		if(code.size() > 8)
			throw std::runtime_error(code + "\nkeycode to long in keycodeToBits");
		unsigned long long bits = 0;
		for(int i = 0; i<code.size(); ++i)
		{
			bits = bits << 8;
			bits = bits | (unsigned char)code[i];
		}
		return bits;
		
	}
	std::string keycodeToKey(std::string code)
	{
		if(code.size() > 8)
			return "Err2Long";
		if(code.size() == 1 && code[0] > 31)
			return code;
		std::string temp;
		unsigned long long bits = keycodeToBits(code);
		for(int i = 0; i<code.size(); ++i)
		{
			temp += std::to_string(int((unsigned char)code[i])) + " ";
		}
		switch(bits)
		{
			case 8:
				return "BACKSPACE";
			case 9:
				return "TAB";
			case 10:
				return "ENTER";
			case 27:
				return "ESC";
			case 1789776:
				return "F1";
			case 1789777:
				return "F2";
			case 1789778:
				return "F3";
			case 1789779:
				return "F4";
			case 1792833:
				return "UP";
			case 1792834:
				return "DOWN";
			case 1792835:
				return "RIGHT";
			case 1792836:
				return "LEFT";
			case 117494068606:
				return "F5";
			case 117494069118:
				return "F6";
			case 117494069374:
				return "F7";
			case 117494069630:
				return "F8";
			case 117494132862:
				return "F9";
			case 117494133118:
				return "F10";
			case 117494133630:
				return "F11";
			case 117494133886:
				return "F12";
			default:
				return std::string("Unknown: ") + std::to_string(bits) + " " + temp;
		}

	}

	std::string bitsToString(unsigned long long b)
	{
		std::string temp;
		for(int k = 0; k<8; ++k)
		{
			temp = " " + temp;
			for(int i = 0; i<8; ++i)
			{
				temp = std::string(b&1?"1":"0") + temp;
				b = b>>1;
			}
		}
		return temp;
	}

}
