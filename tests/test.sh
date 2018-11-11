#!/bin/sh

RED=`tput setaf 1`
GREEN=`tput setaf 2`
YELLOW=`tput setaf 3`

# TEST 1: 
 
num=1
./myfind tests > myfind.txt
find tests > find.txt
DIFF=$(diff myfind.txt find.txt)
if [ "$DIFF" != "" ] ; then
	echo "${RED}Test $num: Check Directory tests NOK"
else
	echo "${GREEN}Test $num: Check directory tests OK"
fi

# TEST 2: 
 
num=2
./myfind . > myfind.txt
find . > find.txt
DIFF=$(diff myfind.txt find.txt)
if [ "$DIFF" != "" ] ; then
	echo "${RED}Test $num: Check directory . NOK"
else
	echo "${GREEN}Test $num: Check directory . OK"
fi


# TEST 3: 
 
num=3
./myfind / > myfind.txt
find / > find.txt
DIFF=$(diff myfind.txt find.txt)
if [ "$DIFF" != "" ] ; then
	echo "${RED}Test $num: Check directory / NOK"
else
	echo "${GREEN}Test $num: Check directory / OK"
fi

# TEST 4: 
 
num=4
./myfind  > myfind.txt
find  > find.txt
DIFF=$(diff myfind.txt find.txt)
if [ "$DIFF" != "" ] ; then
	echo "${RED}Test $num: Check directory \"\" NOK"
else
	echo "${GREEN}Test $num: Check directory \"\" OK"
fi
