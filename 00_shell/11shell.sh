#! /bin/bash


echo "请输入选项"
read option

case $option in
    y* | Y*)
        echo "输入了Yes"
        ;;
    no | N*)
        echo "输入了No"
        ;;
    *)
        echo "输入了其他"
        exit 1
        echo "测试是否退出"
esac