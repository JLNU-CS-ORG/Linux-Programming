/*
 * file name: getterminfo.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Mon 31 Dec 2018 08:40:09 PM CST
 */

#include <stdio.h>
#include <term.h>
#include <curses.h>
#include <stdlib.h>

int main(void)
{
	int nrows, ncolumns;

	setupterm(NULL, fileno(stdout), (int*) 0);

	nrows = tigetnum("lines");
	ncolumns = tigetnum("cols");
	printf("This terminal has %d rows and %d columns\n", 
			nrows, ncolumns);
	exit(0);
}
