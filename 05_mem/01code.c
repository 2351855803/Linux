#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    //获取唯一Key值
    key_t key = ftok("/",2023);

    //生成物理内存,获得物理内存唯一标识符
    int shm_id = shmget(key, 16, IPC_CREAT | 0666);


    //虚拟内存映射物理内存
    char *add = (char *)shmat(shm_id, NULL, 0);


    //操作虚拟内存操作物理内存
#ifdef WRITE
    strcpy(add,"Hello!!!!!!!!!!!\n");
#endif // WRITE

#ifdef READ
    printf("读到的数据为%s\n",add);
#endif // READ

    //断开映射
    shmdt(add);
    return 0;
}
