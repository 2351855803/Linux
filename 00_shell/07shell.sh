#! /bin/bash


echo "todat is `date`"
echo "`sl`"

echo -e "##\n##"

num=10
(
    num=100
    echo "() = $num"
)
echo " = $num"

num1=10
{
    num=100
    echo "() = $num1"
}
echo " = $num1"