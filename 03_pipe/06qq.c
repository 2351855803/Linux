#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>


int main(int argc, char const *argv[])
{
    //创建两个有名管道
    mkfifo("bob_to_lucy",0666);
    mkfifo("lucy_to_bob",0666);

    //创建子进程
    int i = 0;
    for ( i = 0; i < 2; i++)
    {
        pid_t pid = fork();
        if( 0 == pid )
            break;
    }

    if( 0 == i )    //进程1     //写的进程  bob to lucy
    {
        //打开有名管道文件
#ifdef BOB
    int fd = open("bob_to_lucy",O_WRONLY);
#endif // BOB

#ifdef LUCY
    int fd = open("lucy_to_bob",O_WRONLY);
#endif // LUCY
        
        if( fd < 0 )
        {
            perror("open");
            _exit(-1);
        }

        //不断向管道写数据
        while(1)
        {
            char data[128] = "";
            fgets(data,sizeof(data),stdin);
            data[ strlen(data)-1 ] = 0;
            write(fd,data,strlen(data));
#ifdef BOB
    printf("\nbob:%s\n",data);
#endif // BOB  
#ifdef LUCY
    printf("\nlucy:%s\n",data);
#endif // LUCY        
            if( 0 == strcmp( "bye" , data ) )
                break;

        }

        //关闭文件描述符
        close(fd);
        _exit(-1);

    }
    else if ( 1 == i )    //进程2  //读的进程  bob to lucy
    {
        //打开有名管道文件
#ifdef BOB
    int fd = open("lucy_to_bob",O_RDONLY);
#endif // BOB  
#ifdef LUCY
    int fd = open("bob_to_lucy",O_RDONLY);
#endif // LUCY
        if( fd < 0 )
        {
            perror("open");
            _exit(-1);
        }

        //不断从管道读数据
        while(1)
        {
            char data[128] = "";
            read(fd,data,sizeof(data));

#ifdef BOB
    printf("\nlucy:%s\n",data);
#endif // BOB
#ifdef LUCY
    printf("\nbob:%s\n",data);
#endif // LUCY
            if( 0 == strcmp( "bye" , data ) )
                break;

        }

        //关闭文件描述符
        close(fd);
        _exit(-1);
    }
    else if( 2 == i )   //父进程
    {
        while(1)
        {
            pid_t pid = waitpid(-1,NULL,WNOHANG);
            if( pid > 0 )
            {
                printf("进程%d退出\n",pid);
            }
            else if( pid < 0 )
            {
                break;
            }
        }
        _exit(-1);
    }





    return 0;
}
