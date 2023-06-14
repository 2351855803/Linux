#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

//线程的回调函数
void* pthread_fun1(void *arg)
{
    while(1)
    {
        static int i = 0;
        printf("线程1-----------------运行%d秒\n",i);
        sleep(1);
        i++;
    }
    return NULL;

}
void* pthread_fun2(void *arg)
{
    while(1)
    {
        static int i = 0;
        printf("线程2-----------------运行%d秒\n",i);
        sleep(1);
        i++;
    }
    return NULL;
}
int main(int argc, char const *argv[])
{
    pthread_t tid1, tid2;
    pthread_create(&tid1,NULL,pthread_fun1,NULL);
    pthread_create(&tid2,NULL,pthread_fun2,NULL);


    while(1)
    ;
    return 0;
}
