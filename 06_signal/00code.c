#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
int main(int argc, char const *argv[])
{

    pid_t pid = fork();

    if( 0 == pid )
    {
        while(1)
        {
            printf("子进程%d ----------------正在运行\n",getpid());
            sleep(1);
        }
        _exit(-1);
    }
    else if( pid > 0 )
    {
        printf("5s后关闭子进程\n");
        sleep(5);
        kill(pid,9);
        printf("子进程%d已经被父进程%d关闭",pid,getpid());
        wait(NULL);
    }
    
    return 0;
}
