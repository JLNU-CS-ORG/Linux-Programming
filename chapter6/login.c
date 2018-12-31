/*
 * file name: login.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Fri 21 Dec 2018 06:09:11 PM CST
 */

#include <unistd.h>
#include <stdlib.h>
#include <curses.h>
#include <string.h>

#define MAXLEN		256
int main(void)
{
	char name[MAXLEN];
	char password[MAXLEN];
	const char *good_pass = "goodpass";
	int i;
	initscr();
	move(5, 10);
	printw("%s", "Please login:");
	
	move(7, 10);
	printw("%s", "User name:");
	getstr(name);

	move(8, 10);
	printw("%s", "Password:");
	refresh();
	cbreak();
	noecho();

	memset(password, '\0', sizeof(password));
	for (i = 0; i < MAXLEN; i++) {
		password[i] = getch();
		if (password[i] == '\n')
			break;
		move(8, 20 + i);
		addch('*');
		refresh();
	}
	echo();
	nocbreak();
	move(11, 10);
	if (strncmp(good_pass, password, strlen(good_pass)) == 0)
		printw("%s", "password correct");
	else
		printw("%s", "password incorrect");
	refresh();
	sleep(2);
	endwin();
	exit(0);
}
