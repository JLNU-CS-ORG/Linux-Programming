#######################################################################
# file name: first.sh
# author   : Yu Liu
# email    : <ilhanwnz@hotmail.com>
# time     : Tue 18 Dec 2018 11:22:04 PM CST
#######################################################################

#!/bin/sh

for file in *
do 
	if grep -q POSIX $file
	then
		echo $file
	fi
done

exit 0
