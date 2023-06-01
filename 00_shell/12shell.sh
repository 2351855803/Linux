#!/bin/bash

declare -i i=0
declare -i sum=0
for(( i=0 ; i<=100 ; i++ ))
do
    sum=$sum+$i
done
echo "sum为$sum"