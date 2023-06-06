#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
    
    int fd[2];
    pid_t pid = fork();
    printf("初始的读端为%d,写端为%d \n",*(fd+0),*(fd+1));
    pipe(fd);

    if( 0 == pid )
    {
        printf("子进程的读端为%d,写端为%d \n",*(fd+0),*(fd+1));
        _exit(-1);
    }
    else if( pid > 0 )
    {
        printf("父进程的读端为%d,写端为%d \n",*(fd+0),*(fd+1));
        _exit(-1);
    }


    return 0;
}
