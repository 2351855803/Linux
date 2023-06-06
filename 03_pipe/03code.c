#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>


int main(int argc, char const *argv[])
{

    //创建管道
    int fd[2];
    pipe(fd);

    //创建多进程
    int i = 0;
    for ( i = 0; i < 2; i++)
    {
        pid_t pid = fork();
        if( pid == 0 )
            break;
    }

    if( 0 == i )//进程1
    {
        //ps -A
        //重定向管道
        dup2(fd[1],1);
        close(fd[0]);

        execl("/bin/ps","ps","-A",NULL);
        _exit(-1);
    }
    else if( 1 == i )//进程2
    {
        //grep bash
        dup2(fd[0],0);
        close(fd[1]);

        execl("/bin/grep","grep","bash",NULL);
        _exit(-1);

    }
    else if( 2 == i )//父进程
    {
        close(fd[0]);
        close(fd[1]);
        while(1)
        {
            pid_t pid = waitpid(-1,NULL,WNOHANG);
            
            if( 0 == pid )
            {
                continue;
            }
            else if( pid < 0 )
            {
                break;
            }
            else if( pid > 0 )
            {
                printf("进程%d结束\n",pid);
            }
        }
        
    }
    



    return 0;
}
