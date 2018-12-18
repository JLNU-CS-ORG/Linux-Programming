#######################################################################
# file name: for.sh
# author   : Yu Liu
# email    : <ilhanwnz@hotmail.com>
# time     : Tue 18 Dec 2018 11:48:33 PM CST
#######################################################################

for file in $(ls *.sh); do
	echo	$file
done

echo "Enter your password"
read passwd
while [ "$passwd" != "goodpass" ]; do
	echo "Correct passowrd"
	read passwd
done
echo "Password incorrect!"

echo "Is it morning? Please answer y or n"
read cond
case "$cond" in
	y  ) echo "Good Morning";;
	n  ) echo "Good Afternoon";;
	yes) echo "Good Morning";;
	no ) echo "Good Afternoon";;
	*  ) echo "Not recognized command";;
esac 

exit 0
