#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>


int main(int argc, char const *argv[])
{
    

    //创建一个子进程
    pid_t pid = fork();

    //因为会同时存在多个进程，通过进程号来判断进程
    if( pid < 0 )
    {
        perror("创建失败\n");
    }    
    else if( 0 == pid )     //子进程
    {
        while(1)
        {
            printf("当前执行子进程，进程号为%d\n",getpid());
            sleep(1);
        }

    }
    else if( pid > 0 )      //父进程
    {
        while(1)
        {
            printf("当前执行父进程，进程号为%d\n",getpid());
            sleep(1);
        }
    }

    while(1)
    ;


    return 0;
}
