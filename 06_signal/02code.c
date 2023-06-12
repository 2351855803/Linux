#include <stdio.h>
#include <signal.h>


//定义自定义信号处理
void func(int sign)
{
    printf("信号%d执行\n",sign);
}

int main(int argc, char const *argv[])
{
    
    //定义结构体来存储
    struct sigaction sig;

    sig.sa_handler = func;

    sigemptyset(&sig.sa_mask);

    sigaction(2,&sig,NULL);

    while(1)
    ;
    return 0;
}
