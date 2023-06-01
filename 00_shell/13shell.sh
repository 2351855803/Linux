#! /bin/bash


for fileName in `ls`
do
    if [ -d $fileName ];then
        echo "当前文件为：$fileName 是目录文件"
    elif [ -f $fileName ];then
        #echo "当前文件为：$fileName 是普通文件"
        
        case $fileName in
            *.sh)
                echo "$fileName 是普通文件的脚本文件"
                ;;
            *)
                echo "$fileName 是普通文件但不是脚本文件"
                
            
        esac
    fi
    
done