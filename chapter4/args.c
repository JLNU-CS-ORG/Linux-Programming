/*
 * file name: args.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Thu 20 Dec 2018 08:03:47 PM CST
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int i;
	for (i = 0; i < argc; i++) {
		if (argv[i][0] == '-')
			printf("Option: %s\n", argv[i] + 1);
		else
			printf("Arguments %d: %s\n", i, argv[i]);
	}
	exit(0);
}
