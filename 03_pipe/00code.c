#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int fd = dup(1);
    printf("复制到的文件描述符为%d\n",fd);
    write(fd,"hello",strlen("hello"));

    return 0;
}
