#!/bin/sh


test -e tset.txt
echo " $? "


test "123" = "456"
echo "$?"

test "123" != "456"
echo "$?"

test -z "123"
echo "$?"

test -n "123"
echo "$?"

str1=""
test -z $str1
echo "$?"