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
 
        printf("当前执行子进程，进程号为%d,父进程进程号为%d\n",getpid(),getppid());
        sleep(1);
        getchar();
   

    }
    else if( pid > 0 )      //父进程
    {
        printf("父进程三秒后关闭\n");
        sleep(3);
    }
    return 0;
}
