#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char const *argv[])
{


    unsigned char temp[128] = "";
    printf("正在读取数据.....\n");


    //获取文件状态标记
    int flag = fcntl(0,F_GETFL);
    //修改文件状态标记
    flag |= O_NONBLOCK;
    //把修改完后的状态标记设置回去
    fcntl(0,F_SETFL,flag);

    int state = read(0,temp,sizeof(temp)/sizeof(temp[0]));
 
    printf("读取到的数据为%s\n",temp);




    return 0;
}
