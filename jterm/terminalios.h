#ifndef JTBTERMINALIOS
#define JTBTERMINALIOS

#include <termios.h>
#include <unistd.h>
#include <deque>

namespace jtb
{
	class terminalios
	{
	public:
		terminalios()
		{
			tcgetattr(STDIN_FILENO, &current);
			tcsetattr(STDIN_FILENO, TCSAFLUSH, &current);
			save();
		}
		std::deque<termios> saved;
		termios current;
		void save();
		bool load(short i = 0);
		void reload();

		void rawMode(bool on);
		bool rawMode();

	private:
		bool rawModeState;

	};
}

#endif
