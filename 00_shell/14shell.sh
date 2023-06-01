#! /bin/bash

#导入15shell.sh的函数
source 15shell.sh


echo "请输入两个数字"
read num1 num2
my_add $num1 $num2
echo "得到的数字为：$?"
