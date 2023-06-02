#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>


int main(int argc, char const *argv[])
{
    int i = 0;

    for(i = 0; i < 2; i++ )
    {
        pid_t pid = fork();
        printf("当前进程为%d,父进程为%d\n",getpid(),getppid());
        if( 0 == pid )
            break;
    }

    while(1)
    ;
    

    return 0;
}
