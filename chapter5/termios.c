/*
 * file name: termios.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Mon 31 Dec 2018 08:33:26 PM CST
 */

#include <termios.h>
#include <stdio.h>
#include <stdlib.h>

#define PASSWD_LEN	8

int main(void)
{
	struct termios init_setting, new_setting;

	char password[PASSWD_LEN + 1];

	tcgetattr(fileno(stdin), &init_setting);
	new_setting = init_setting;
	new_setting.c_lflag &= ~ECHO;	/* Disabled echo functional */
	
	printf("Enter Passowrd: ");

	if (tcsetattr(fileno(stdin), TCSAFLUSH, &new_setting) != 0) {
		fprintf(stderr, "Could not set attributes\n");
	} else {
		fgets(password, PASSWD_LEN, stdin);
		tcsetattr(fileno(stdin), TCSANOW, &init_setting);
		fprintf(stdout, "\nYou entered %s\n", password);
	}
	exit(0);

}
