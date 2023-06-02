#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>


int main(int argc, char const *argv[])
{
    
    pid_t pid = getpid();

    printf("当前进程号为%d \n",pid);
    while(1)
    ;
    

    return 0;
}
