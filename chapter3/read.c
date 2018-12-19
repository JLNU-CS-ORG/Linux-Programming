/*
 * file name: read.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Wed 19 Dec 2018 10:07:06 AM CST
 */

#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	char buf[128];
	int nread;
	nread = read(0, buf, 128);
	if (nread == -1)
		write(2, "Read error\n",11);
	if (write(1, buf, nread) != nread)
		write(2, "Write error\n", 12);
	exit(0);
}
