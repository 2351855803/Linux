#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    
    //建立内存映射
    //打开文件
    int fd = open("temp.txt",O_RDWR|O_CREAT,0666);

    //填充文件
    truncate("temp.txt",16);

    //建立内存映射
    char *add = (char *)mmap(NULL, 16, PROT_READ|PROT_WRITE, MAP_SHARED,fd, 0);

    printf("read文件读取到的内容为%s\n",add);

    //断开映射
    munmap(add,16);




    return 0;
}
