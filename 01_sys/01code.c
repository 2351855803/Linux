#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    
    //打开文件
    int fd = open("a.txt", O_RDWR | O_CREAT , 0777);
    if( fd < 0 )
    {
        perror("open");
    }

    char temp[128] = "";
    fgets(temp,128,stdin);
    //写入文件
    write(fd,temp,strlen(temp));
    //关闭文件
    close(fd);

    
    return 0;
}
