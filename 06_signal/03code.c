#include <stdio.h>
#include <signal.h>
#include <unistd.h>


int main(int argc, char const *argv[])
{
    
    //创建信号集
    sigset_t sig;

    //因为定义在栈区，初始化防止随机值
    sigemptyset(&sig);


    //往信号集中添加信号
    sigaddset(&sig,2);

    //把信号集添加到信号阻塞集中
    sigprocmask(SIG_BLOCK,&sig,NULL);

    printf("5s后,信号阻塞集中Ctrl+C产生信号将会被剔除\n");
    sleep(5);


    //把信号从阻塞集中剔除
    sigprocmask(SIG_UNBLOCK,&sig,NULL);

    //验证信号是否发出
    while(1)
    ;

    return 0;
}
