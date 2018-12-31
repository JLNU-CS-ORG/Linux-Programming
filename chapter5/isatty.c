/*
 * file name: isatty.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Fri 21 Dec 2018 12:38:17 AM CST
 */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(void)
{
	FILE *out;
	if (!isatty(fileno(stdout))) {
		fprintf(stderr, "Not a terminal!\n");
	}
	out = fopen("/dev/tty", "w");
	fprintf(out, "Hello\n");
	printf("Just a test program\n");
	return 0;
}
