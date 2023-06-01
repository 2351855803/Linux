#!/bin/bash


echo "请输入文件名"
read fileName

if [ -e $fileName.txt ] && [ -e 4455.txt ]; then
    echo "文件存在"
    cat $fileName.txt
else
    #echo "文件不存在"
    touch $fileName.txt
    echo "Hello" >> $fileName.txt
     
fi
