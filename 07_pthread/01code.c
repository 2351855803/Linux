#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

//线程的回调函数
void* pthread_fun1(void *arg)
{
    static int i = 0;
    while( i <= 5 )
    {

        printf("线程1-----------------运行%d秒\n",i);
        sleep(1);
        i++;
    }
    printf("线程1退出   \n");
    return NULL;

}
void* pthread_fun2(void *arg)
{
    static int i = 0;
    while( i <= 3 )
    {
        printf("线程2-----------------运行%d秒\n",i);
        sleep(1);
        i++;
    }
    printf("线程2退出   \n");
    return NULL;
}
int main(int argc, char const *argv[])
{
    //创建线程
    pthread_t tid1, tid2;
    pthread_create(&tid1,NULL,pthread_fun1,NULL);
    pthread_create(&tid2,NULL,pthread_fun2,NULL);

    //进程中回收线程资源
    if( !pthread_join(tid1,NULL) )
        printf("线程1回收成功\n");
    if( !pthread_join(tid2,NULL) )
        printf("线程2回收成功\n");


    while(1)
    ;
    return 0;
}
