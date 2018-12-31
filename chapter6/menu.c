/*
 * file name: menu.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Mon 31 Dec 2018 09:28:56 PM CST
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>
#include <unistd.h>

void echo_menu(void);
void get_choice(void);
int main(void)
{
	initscr();
	
	if (!has_colors()) {
		endwin();
		fprintf(stderr, "Not support color on this terminal\n");
		exit(-1);
	}
	if (start_color() != OK) {
		endwin();
		fprintf(stderr, "Not initialize colors\n");
		exit(-2);
	}
	while (1) {
		echo_menu();
		get_choice();
		sleep(2);
		clear();
	}
	endwin();
	exit(0);
}

void echo_menu(void)
{
	int mid;
	char title[] = "DREAM MENU\n";
	char menu1[]  = "1.BECOME SOFTWARE ENGINEER	- COST 100$    \n";
	char menu2[]  = "2.MARRIED WITH HANWNZ		- COST 10000$  \n";
	char menu3[]  = "3.MARRIED WITH DAKOTA		- COST 1000000$\n";

	int len = strlen(title);
	mid = (COLS - len) / 2;
#ifdef DEBUG
	move(0, 0);
	printw("%d", mid);
#endif
	move(0, mid);
	printw(title);
	mid = (COLS - strlen(menu1)) / 2;
	
	init_pair(1, COLOR_RED, COLOR_WHITE);
	init_pair(2, COLOR_RED, COLOR_GREEN);
	init_pair(3, COLOR_GREEN, COLOR_RED);

	attrset(COLOR_PAIR(1) | A_BOLD);
	move(2, mid);
	printw(menu1);
	attroff(COLOR_PAIR(1) | A_BOLD);
	refresh();
	
	attrset(COLOR_PAIR(2) | A_BOLD);
	move(3, mid);
	printw(menu2);
	attroff(COLOR_PAIR(2) | A_BOLD);
	refresh();

	attrset(COLOR_PAIR(3) | A_BOLD);
	move(4, mid);
	printw(menu3);
	attroff(COLOR_PAIR(3) | A_BOLD);
	refresh();
}
void get_choice(void)
{
	int choice;
	move(6, 0);
	printw("Please enter your choice for this menu: ");
	refresh();
	choice = getch();
	move(6, strlen("Please enter your choice for this menu: "));
	addch('*');
	refresh();
	switch (choice) {
	case '1':
	case '2':
	case '3':
		move(7, 0);
		printw("You already chosen a item, we will keep secret.");
		break;
	case 'q':
		exit(-1);
	default:
		move(7, 0);
		printw("No this item, Please try again.");
		break;
	}
	refresh();
}
