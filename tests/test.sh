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


# TEST 5: 
 
num=5
./myfind ../ > myfind.txt
find ../ > find.txt
DIFF=$(diff myfind.txt find.txt)
if [ "$DIFF" != "" ] ; then
	echo "${RED}Test $num: Check directory ../ NOK"
else
	echo "${GREEN}Test $num: Check directory ../ OK"
fi


# TEST 6: 
 
num=6
./myfind tests . > myfind.txt
find tests . > find.txt
DIFF=$(diff myfind.txt find.txt)
if [ "$DIFF" != "" ] ; then
	echo "${RED}Test $num: Check directories tests_and_\".\" NOK"
else
	echo "${GREEN}Test $num: Check directories tests_and_\".\" OK"
fi


# TEST 7: 
 
num=7
./myfind -d tests/ > myfind.txt
find tests/ -d > find.txt
DIFF=$(diff myfind.txt find.txt)
if [ "$DIFF" != "" ] ; then
	echo "${RED}Test $num: Check directories -d NOK"
else
	echo "${GREEN}Test $num: Check directories -d OK"
fi


# TEST 8: 
 
num=8
./myfind -L . > myfind.txt
find -L . > find.txt
DIFF=$(diff myfind.txt find.txt)
if [ "$DIFF" != "" ] ; then
	echo "${RED}Test $num: Check directories -L NOK"
else
	echo "${GREEN}Test $num: Check directories -L OK"
fi


# TEST 9: 
 
num=9
./myfind -H . > myfind.txt
find -H . > find.txt
DIFF=$(diff myfind.txt find.txt)
if [ "$DIFF" != "" ] ; then
	echo "${RED}Test $num: Check directories -H NOK"
else
	echo "${GREEN}Test $num: Check directories -H OK"
fi


# TEST 10: 
 
num=10
./myfind -P tests > myfind.txt
find -P tests > find.txt
DIFF=$(diff myfind.txt find.txt)
if [ "$DIFF" != "" ] ; then
	echo "${RED}Test $num: Check directories -P NOK"
else
	echo "${GREEN}Test $num: Check directories -P OK"
fi


# TEST 11: 
 
num=11
./myfind -d -L . > myfind.txt
find -L . -d > find.txt
DIFF=$(diff myfind.txt find.txt)
if [ "$DIFF" != "" ] ; then
	echo "${RED}Test $num: Check directories -d_-L NOK"
else
	echo "${GREEN}Test $num: Check directories -d_-L OK"
fi


# TEST 12: 
 
num=12
./myfind -H -P . > myfind.txt
find -H -P . > find.txt
DIFF=$(diff myfind.txt find.txt)
if [ "$DIFF" != "" ] ; then
	echo "${RED}Test $num: Check directories -H_-P NOK"
else
	echo "${GREEN}Test $num: Check directories -H_-P OK"
fi


# TEST 13: 
 
num=13
./myfind -d -L -H -P . > myfind.txt
find -L -H -P . -d > find.txt
DIFF=$(diff myfind.txt find.txt)
if [ "$DIFF" != "" ] ; then
	echo "${RED}Test $num: Check directories all_options NOK"
else
	echo "${GREEN}Test $num: Check directories all_options OK"
fi
