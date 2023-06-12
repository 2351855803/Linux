#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/time.h>


void func(int sig)
{
    static int count = 0;
    printf("%d信号触发\n",sig);


    //当接受到五次alarm信号之后，杀死进程
    count++;
    if( 5 == count )
    {
        printf("收到五次ALARM信号,杀死进程\n");
        kill(getpid(),9);
        
    }
}

int main(int argc, char const *argv[])
{
    

    //使用setitimer定时器
    //us级别
    //int setitimer(int which, const struct itimerval *new_value,struct itimerval *old_value);
    struct itimerval time;

    //设定五秒后触发
    time.it_interval.tv_sec = 2;
    time.it_interval.tv_usec = 0;

    //设定周期
    time.it_value.tv_sec = 5;
    time.it_value.tv_usec = 0;

    //注册信号，发送信号的时候调用的是这个函数
    signal(SIGALRM,func);

    //使用定时器
    setitimer(ITIMER_REAL,&time,NULL);

    while(1)
    ;




    return 0;
}
