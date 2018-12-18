#######################################################################
# file name: variable.sh
# author   : Yu Liu
# email    : <ilhanwnz@hotmail.com>
# time     : Tue 18 Dec 2018 11:30:08 PM CST
#######################################################################

#!/bin/sh

myvar = "Hi there"

echo $myvar
echo "$myvar"
echo '$myvar'
echo \$myvar

echo Enter some text
read myvar

echo '$myvar' now equals $myvar
exit 0
