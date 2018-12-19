/*
 * file name: write.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Wed 19 Dec 2018 10:05:33 AM CST
 */

#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	if ((write(1, "Here is some data\n", 18)) != 18)
		write(2, "A write error has occured.", 24);
	exit(0);
}
