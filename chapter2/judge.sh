#######################################################################
# file name: judge.sh
# author   : Yu Liu
# email    : <ilhanwnz@hotmail.com>
# time     : Tue 18 Dec 2018 11:41:34 PM CST
#######################################################################

#!/bin/sh

if [ -f /bin/bash ]
then
	echo "file /bin/bash exists"
fi

if [ -d /bin/bash ]
then
	echo "/bin/bash is a directory"
else
	echo "/bin/bash is not a directory"
fi

echo "Is it morning? Please answer y or n"
read var

if [ "$var" = "y" ]
then
	echo "Good morning"
elif [ "$var" = "n" ]
then
	echo "Good afternoon"
else 
	echo "Command not recognized. please enter y or n."
fi
exit 0
