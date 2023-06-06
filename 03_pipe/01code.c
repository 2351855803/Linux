#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>



int main(int argc, char const *argv[])
{
    //创建管道通信两边的文件描述符
    int fd[2];
    pipe(fd);
    //创建子进程
    pid_t pid = fork();

    //子进程
    if( 0 == pid )
    {
        while(1)
        {
            close(fd[1]);
            char data[128] = "";
            //sleep(5);
            printf("子进程%d 接受信息\n",getpid());
            //sleep(1);
            read(fd[0],data,sizeof(data));

            printf("子进程%d 接受到信息 %s\n",getpid(),data);

            //close(fd[0]);
        }

    }
    else if( pid > 0 )  //父进程
    {
        //父进程作为写端，关闭读端文件描述符

        while(1)
        {
            close(fd[0]);
            char data[128] = "";
            scanf("%s",data);
            printf("父进程%d 发送信息\n",getpid());
 
            write(fd[1],data,strlen(data));

            printf("父进程%d 写入完成\n",getpid());
            //wait(NULL);            
        }
    

    }

    return 0;
}
