#######################################################################
# file name: trap.sh
# author   : Yu Liu
# email    : <ilhanwnz@hotmail.com>
# time     : Wed 19 Dec 2018 12:03:25 AM CST
#######################################################################

#!/bin/sh

trap 'rm -rf /tmp/myfile' INT
echo Creating file /tmp/myfile
date > /tmp/myfile

echo "Press CTRL-C to int ..."
while [ -f "/tmp/myfile" ]; do
	echo File exists
	sleep 1
done

echo The file no longer exists
