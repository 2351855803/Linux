#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
typedef struct msg
{
    char task_name[16];
    int time;
}MSG;





//线程函数
void* pthread_fun(void* arg)
{
    /*为了防止创建线程后，由于主线程中结构体
    是一直在创建的，防止多个线程同时操作同一
    块结构体空间，简而言之就是主线程中结构体
    传递指针过来，而主线程中的结构体在重新循环
    的时候会再次创建，不能直接在该线程中接受
    主线程中的结构体指针。否则可能导致多个线程
    操控同一块内存*/

    MSG msg = *((MSG*)arg);

    int i = msg.time;
    printf("线程%s执行,%d秒后停止\n",msg.task_name,i);
    for ( ; i > 0; i--)
    {
        sleep(1);
    }
    printf("线程%s退出\n",msg.task_name);
    
    //线程退出
    pthread_exit(NULL);

    return NULL;
}




int main(int argc, char const *argv[])
{
    



    //通过循环以及阻塞不断创建线程
    while(1)
    {

        MSG my_msg;

        //输入任务的名字，同时阻塞
        printf("请输入任务的名字:\n");
        
        fgets(my_msg.task_name,sizeof(my_msg.task_name),stdin);
        my_msg.task_name[strlen(my_msg.task_name)-1] = 0;

        printf("请输入运行时间:\n");
        scanf("%d",&my_msg.time);
        //接受scanf的回车
        getchar();


        pthread_t pthread;
        //创建线程
        pthread_create(&pthread,NULL,pthread_fun,&my_msg);
        //线程分离
        pthread_detach(pthread);



    }




    return 0;
}
