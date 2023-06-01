#! /bin/bash

echo "请输入Yes Or No"
read option
if [ $option = "yes" ];then
    echo "选择了Yes"
elif [ $option = "no" ];then
    echo "选择了No"
else
    echo "其他选项"
fi

