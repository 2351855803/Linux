#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    //创建有名管道
    mkfifo("./fifo",0666);

    int fd = open("./fifo",O_RDONLY);
    if( fd < 0 )
    {
        perror("open");
    }
    printf("读端打开成功\n");
    while(1)
    {
   
        char data[128] = "";
        read(fd,data,sizeof(data));
        printf("读取到的数据为%s  \n",data);

        if( strcmp( data , "bye" ) == 0 )
            break;
    }
    close(fd);
    return 0;
}
