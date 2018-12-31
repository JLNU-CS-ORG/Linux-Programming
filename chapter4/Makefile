#######################################################################
# file name: Makefile
# author   : Yu Liu
# email    : <ilhanwnz@hotmail.com>
# time     : Mon 31 Dec 2018 06:17:16 PM CST
#######################################################################

PROG := prog1 prog2 prog3 prog4 prog5 prog6 prog7 
all: $(PROG)
	@echo "#Automatic generate program successful!"
prog1:
	gcc args.c -o $@
prog2:
	gcc command.c -o $@
prog3:
	gcc ctime.c -o $@
prog4:
	gcc environ.c -o $@
prog5:
	gcc gmtime.c -o $@
prog6:
	gcc tmpnam.c -o $@
prog7:
	gcc user.c -o $@
clean:
	rm $(PROG) -rf
