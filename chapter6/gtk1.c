/*
 * file name: gtk1.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Fri 21 Dec 2018 07:08:04 PM CST
 */

#include <gtk/gtk.h>

int main(int argc, char *argv[])
{
	GtkWidget *window;
	gtk_init(&argc, &argv);
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_widget_show(window);
	gtk_main();
	return 0;
}
