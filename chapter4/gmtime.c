/*
 * file name: gmtime.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Thu 20 Dec 2018 11:01:31 PM CST
 */

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	struct tm *ptm;
	time_t tm;
	(void) time(&tm);
	ptm = gmtime(&tm);
	printf("Raw time is %ld\n", tm);
	printf("gmtime gives:\n");
	printf("Date: %02d/%02d/%02d\n",
			ptm->tm_year, ptm->tm_mon + 1, ptm->tm_mday);
	printf("time: %02d:%02d:%02d\n",
			ptm->tm_hour, ptm->tm_min, ptm->tm_sec);
	exit(0);
}
