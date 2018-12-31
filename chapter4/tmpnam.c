/*
 * file name: tmpnam.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Mon 31 Dec 2018 06:22:54 PM CST
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char tmpname[L_tmpnam];
	//char *filename;
	FILE *tmpfp;
	/* DO NOT! Don't use tmpnam function. it is very dangerous */
	//filename = tmpnam(tmpname);
	int fd;
	fd = mkstemp(tmpname);
	tmpfp = fdopen(fd, "r");
	//printf("Temp file name is: %s\n", filename);
	
	tmpfp = tmpfile();
	if (tmpfp)
		printf("#Open temporary file successfull\n");
	else
		perror("Open error");
	exit(0);

}
