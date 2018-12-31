/*
 * file name: ctime.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Thu 20 Dec 2018 11:11:28 PM CST
 */

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	time_t timeval;
	(void) time(&timeval);
	printf("The date is: %s\n", ctime(&timeval));
	exit(-1);
}
