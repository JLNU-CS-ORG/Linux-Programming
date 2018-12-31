/*
 * file name: nchello.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Mon 31 Dec 2018 09:12:44 PM CST
 */

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>

int main(void)
{
	initscr();
	
	move(5, 15);
	printw("%s", "Hello ncurses");
	refresh();
	beep();
	sleep(1);
	endwin();
	exit(0);
}
