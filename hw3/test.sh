#!/bin/sh
PROG1="printFile"
PROG2="myPhoneBook"
gcc -Wall $PROG1.c -o $PROG1
./$PROG1 $PROG1.c

gcc -Wall $PROG2.c -o $PROG2
./$PROG2
