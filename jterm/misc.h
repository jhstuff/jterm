#ifndef JTERMMISC
#define JTERMMISC
#include <iostream>
#include <termios.h>
#include <sys/ioctl.h>
#include <string>
#include <fstream>
#include <sstream>
namespace jtb
{

//ESC[38;2;⟨r⟩;⟨g⟩;⟨b⟩ m Select RGB foreground color
//ESC[48;2;⟨r⟩;⟨g⟩;⟨b⟩ m Select RGB background color
void cursor(bool on);
void altScreen(bool on);
void Rawmode(bool on, bool safemode = true);
//https://viewsourcecode.org/snaptoken/kilo/02.enteringRawMode.html
//Enable rawmode for terminal (no input sugarcoating)

void setCursor(int x=1, int y=1);
void getWinSize(unsigned short * x, unsigned short * y, unsigned short * xPixel = nullptr, unsigned short * yPixel = nullptr);

std::string readFile(std::string filename, bool * err = nullptr);

}
#endif
