#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>



int main(int argc, char const *argv[])
{
    struct stat status;
    stat("a.txt",&status);

    //通过宏判断文件类型
    if( S_ISREG(status.st_mode) )
    {
        printf("为普通文件\n");
    }
    else
    {
        printf("其他文件\n");
    }

    if( (status.st_mode & S_IRWXU) == S_IRWXU )
    {
        printf("所有者具有读写操作权限\n");
    }
    if( (status.st_mode & S_IRWXG)  == S_IRWXG )
    {
        printf("同组用户具有读写操作权限\n");
    }
    if( (status.st_mode & S_IRWXO) == S_IRWXO )
    {
        printf("其他用户具有读写操作权限\n");
    }


    if( status.st_mode & S_IROTH )
    {
        printf("其他用户有读权限\n");
    }
    if( status.st_mode & S_IWOTH )
    {
        printf("其他用户有写权限\n");
    }
    if( status.st_mode & S_IXOTH )
    {
        printf("其他用户有操作权限\n");
    }

    return 0;
}
