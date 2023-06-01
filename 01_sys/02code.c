#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    
    //打开文件
    int fd = open("a.txt", O_RDONLY);
    if( fd < 0 )
    {
        perror("open");
    }

    char temp[128] = "";
    
    read(fd,temp,sizeof(temp));
    printf("%s",temp);
    //关闭文件
    close(fd);

    
    return 0;
}
