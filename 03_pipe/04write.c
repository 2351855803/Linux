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

    int fd = open("./fifo",O_WRONLY);
    if( fd < 0 )
    {
        perror("open");
    }
    printf("写端打开成功\n");
    while(1)
    {
        
        char data[128] = "";
        printf("请输入数据\n");
        fgets(data,sizeof(data),stdin);
        //data[strlen(data)-1] = 0;
        //发送
        write(fd,data,strlen(data));

        if( strcmp( data , "bye" ) == 0 )
            break;
    }
    close(fd);
    return 0;
}
