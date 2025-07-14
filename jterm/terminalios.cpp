#include "terminalios.h"

namespace jtb
{

void terminalios::save()
{
	saved.push_back(current);
}

bool terminalios::load(short i)
{
	if(false) //fix
		return true;
	current = saved[i];
	reload();
	return false;
}

void terminalios::reload()
{
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &current);
}

void terminalios::rawMode(bool on)
{
	
//https://viewsourcecode.org/snaptoken/kilo/02.enteringRawMode.html
//Enable rawmode for terminal (no input sugarcoating)
	if(on)
		current.c_lflag &= ~(ECHO | ICANON);
	else
		current.c_lflag |= (ECHO | ICANON);
	reload();
}




}
