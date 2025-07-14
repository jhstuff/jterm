#include "misc.h"

namespace jtb
{

	
//ESC[38;2;⟨r⟩;⟨g⟩;⟨b⟩ m Select RGB foreground color
//ESC[48;2;⟨r⟩;⟨g⟩;⟨b⟩ m Select RGB background color
	void cursor(bool on)
	{
		if(on)
			std::cout<<"\033[?25h";
		else
			std::cout<<"\033[?25l";

	}
	void altScreen(bool on)
	{
		if(on)
			std::cout<<"\033[?1049h";
		else
			std::cout<<"\033[?1049l";
	}

	void Rawmode(bool on, bool safemode)
//https://viewsourcecode.org/snaptoken/kilo/02.enteringRawMode.html
//Enable rawmode for terminal (no input sugarcoating)
        {
		static bool safe = false;
		//only allow turning on if off and off if on
		static termios oldterm;
		static termios newterm;
		if( (safe == on) && (safemode) )
			return;
		safe = on;
		if(on)
		{
                	tcgetattr(0, &oldterm);
                	newterm = oldterm;
                	newterm.c_lflag &= ~(ECHO | ICANON);
                	tcsetattr(0, TCSAFLUSH, &newterm);
		}
		else
			tcsetattr(0, TCSAFLUSH, &oldterm);

        }

	void setCursor(int x, int y)
	{
		std::cout<<("\033[" + std::to_string(x) + ";" + std::to_string(y) + "H");
	}

	void getWinSize(unsigned short * x, unsigned short * y, unsigned short * xPixel, unsigned short * yPixel)
	{
		struct winsize w;
		ioctl(0, TIOCGWINSZ, &w);
//https://stackoverflow.com/questions/23369503/get-size-of-terminal-window-rows-columns
//https://stackoverflow.com/questions/1022957/getting-terminal-width-in-c/1022961#1022961
		if(x)
			*x=w.ws_col;
		if(y)
			*y=w.ws_row;
		if(xPixel)
			*xPixel=w.ws_xpixel;
		if(yPixel)
			*yPixel=w.ws_ypixel;
	}

	std::string readFile(std::string filename, bool * err)
	{
		std::fstream f;
		f.open(filename);
		if(!f.is_open())
		{
			f.clear();
			std::string t = filename + " could not be read";
			if(err == nullptr)
				throw std::runtime_error(t);
			return "";
		}
		std::stringstream b;
		b << f.rdbuf();
		return b.str();

		
	}


}

