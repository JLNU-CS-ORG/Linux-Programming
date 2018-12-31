/*
 * file name: echotext.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Mon 31 Dec 2018 09:16:50 PM CST
 */

#include <stdio.h>
#include <unistd.h>
#include <curses.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	const char t1[] = " Text1";
	const char t2[] = " Text2";
	const char *trace;

	initscr();
	move(5, 15);
	attron(A_BOLD);
	printw("%s", "Line1");
	attroff(A_BOLD);
	refresh();
	sleep(1);

	move(8, 15);
	attron(A_STANDOUT);
	printw("%s", "Thunder and lighting");
	attroff(A_STANDOUT);
	refresh();
	sleep(1);
	
	attron(A_DIM);
	trace = t1 + strlen(t1) - 1;
	do {
		move(10, 10);
		insch(*trace--);
	} while (trace != t1);
	
	trace = t2 + strlen(t2) - 1;
	do {
		move(13, 10);
		insch(*trace--);
	} while (trace != t2);
	attroff(A_DIM);
	refresh();
	sleep(1);
	
	move(LINES - 1, COLS - 1);
	refresh();
	sleep(1);

	endwin();
	exit(0);
}
