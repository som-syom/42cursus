#include <termios.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
	struct termios raw;

	// raw = orig_termios;  /* copy original and then modify below */

	tcgetattr(0, &raw);
	/* input modes - clear indicated ones giving: no break, no CR to NL,
	   no parity check, no strip char, no start/stop output (sic) control */
	// raw.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);

	/* output modes - clear giving: no post processing such as NL to CR+NL */
	// raw.c_oflag &= ~(OPOST);

	/* control modes - set 8 bit chars */
	// raw.c_cflag |= (CS8);

	/* local modes - clear giving: echoing off, canonical off (no erase with
	   backspace, ^U,...),  no extended functions, no signal chars (^Z,^C) */
	// raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
	raw.c_lflag &= ~(ICANON | ECHO);
	/* control chars - set return condition: min number of bytes and timer */
	raw.c_cc[VMIN] = 5; raw.c_cc[VTIME] = 8; /* after 5 bytes or .8 seconds
												after first byte seen      */
	raw.c_cc[VMIN] = 0; raw.c_cc[VTIME] = 0; /* immediate - anything       */
	raw.c_cc[VMIN] = 2; raw.c_cc[VTIME] = 0; /* after two bytes, no timer  */
	raw.c_cc[VMIN] = 0; raw.c_cc[VTIME] = 8; /* after a byte or .8 seconds */

	/* put terminal in raw mode after flushing */
	tcsetattr(0 ,TCSAFLUSH,&raw);

	while(1)
	{
		char buf[256] = {0};
		int sz = read(0, buf, 256);
		if (sz)
		{
			//`~~
			write(1, &"0123456789"[sz], 1);
			write(1, buf, sz);
		}
	}
}
