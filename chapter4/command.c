/*
 * file name: command.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Mon 31 Dec 2018 05:41:15 PM CST
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <getopt.h>

#define _GNU_SOURCE

void echo_time(void);
void echo_help(void);

int main(int argc, char *argv[])
{
	int opt;
	struct option longopts[] = {
		{"restart", 0, NULL, 'r'},
		{"echo", 1, NULL, 'e'},
		{"time", 0, NULL, 't'},
		{"date", 0, NULL, 'd'},
		{"help", 0, NULL, 'h'},
		{     0, 0,    0,   0},
	};
	char *args[] = {"/sbin/reboot", NULL};
	if (argc < 2) {
		printf("Usage: prog2 -<args>|--<longargs> [opts]\n");
		exit(-1);
	}
	while ((opt = getopt_long(argc, argv, ":re:tdh",
					longopts, NULL)) != -1) {
		switch (opt) {
		case 'r':
			printf("Restarting...\n");
			execve("/sbin/reboot", args, NULL);
			break;
		case 'e':
			printf("%s\n", optarg);
			break;
		case 'd':
		case 't':
			echo_time();
			break;
		case 'h':
			echo_help();
			break;
		case ':':
			printf("prog2 -e|--echo <strings>\n");
			break;
		case '?':
			printf("Unknow option: %c\n"
			       "Please try -h|--help options\n", optopt);
			break;
		}
	}
	exit(0);
}
void echo_time(void)
{
	time_t timeval;
	(void)time(&timeval);
	printf("%s", ctime(&timeval));
}
void echo_help(void)
{
	printf("prog2 			This program is just a testing program\n"
	       "\n"
	       "-r|--restart    	Restart this system\n"
	       "-t|--time 		Echo current time\n"
	       "-d|--date		The same as |-t|\n"
	       "-e|--echo		Echo strings\n"
	       "-h|--help		Print help message\n");
}
