/*
 * file name: kbhit.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Mon 31 Dec 2018 08:59:00 PM CST
 */

#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <curses.h>
#include <unistd.h>

static struct termios initsetting, newsetting;

static int peek_char = -1;

void init_keyboard();
void close_keyboard();

int kbhit();
int readch();

int main(void)
{
	int ch = 0;
	
	init_keyboard();
	while (ch != 'q') {
		if (kbhit()) {
			printf("Please enter you input:\n");
			ch = readch();
			printf("You hit the %c\n character\n", ch);
		}
	}
	close_keyboard();
	exit(0);
}

void init_keyboard()
{
	tcgetattr(0, &initsetting);
	newsetting = initsetting;
	newsetting.c_lflag &= ~ICANON;
	newsetting.c_lflag &= ~ECHO;
	newsetting.c_lflag &= ~ISIG;
	newsetting.c_cc[VMIN] = 1;
	newsetting.c_cc[VTIME] = 0;
	tcsetattr(0, TCSANOW, &newsetting);
}
void close_keyboard()
{
	tcsetattr(0, TCSANOW, &initsetting);
}

int kbhit()
{
	char ch;
	int nread;

	if (peek_char != -1)
		return 1;
	newsetting.c_cc[VMIN] = 0;
	tcsetattr(0, TCSANOW, &newsetting);
	nread = read(0, &ch, 1);
	newsetting.c_cc[VMIN] = 1;
	tcsetattr(0, TCSANOW, &newsetting);

	if (nread == 1) {
		peek_char = ch;
		return 1;
	}
	return 0;	
}
int readch()
{
	char ch;
	if (peek_char != -1) {
		ch = peek_char;
		peek_char = -1;
		return ch;
	}
	read(0, &ch, 1);
	return ch;
}
