#!/bin/sh

RED=`tput setaf 1`
GREEN=`tput setaf 2`
YELLOW=`tput setaf 3`

# TEST ONE: 
 
num=1
state="./"
t=$(./myfind ./)
error=$?
expected=$(find ./)
if [ "$t" != "$expected" ] ; then
	echo "${RED}Error test $num"
    echo "${RED}bad value on <$state>"
    echo "${YELLOW}got <$t> ${RED}expected <$expected>"
else
	echo "${GREEN}Test $num OK"
fi

# TEST TWO: 
 
num=2
state="../"
t=$(./myfind ../)
error=$?
expected=$(find ../)
if [ "$t" != "$expected" ] ; then
	echo "${RED}Error test $num"
    echo "${RED}bad value on <$state>"
    echo "${YELLOW}got <$t> ${RED}expected <$expected>"
	exit
else
	echo "${GREEN}Test $num OK"
fi
