/*
 * file name: copy.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Wed 19 Dec 2018 10:16:16 AM CST
 */

#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main(void)
{
	char c;
	int fd1, fd2;
	fd1 = open("file.in", O_RDONLY);
	fd2 = open("file.out", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	while (read(fd1, &c, 1) == 1)
		write(fd2, &c, 1);
	exit(0);
}
