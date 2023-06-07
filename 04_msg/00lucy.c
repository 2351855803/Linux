#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
typedef struct _msg
{
    long mstype;
    char mstext[64];
}MSG;

int main(int argc, char const *argv[])
{
    //获取唯一键值
    key_t key = ftok("/",2023);
    printf("KEY为%#x\n",key);
    //通过key值生成消息队列
    int msg = msgget(key, IPC_CREAT | 0666 );
    printf("消息队列标识符为%d\n",msg);


    //编辑消息队列信息
    MSG _msg;
    memset(&msg,0,sizeof(msg));

    //接受消息
    printf("lucy准备接受消息...\n");
    msgrcv(msg, &_msg, sizeof(_msg)-sizeof(long), 20,0);
    printf("接收到消息%s\n",_msg.mstext);





    return 0;
}
