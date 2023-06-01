#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    
    //传入参数的判断
    if( argc != 3 )
    {
        printf("传入参数个数错误\n");
        return 0;
    }
    //拼接文件地址
    char fileAdd[128] = "";
    
    sprintf(fileAdd,"%s/%s",argv[2],argv[1]);
    //printf("%s\n",fileAdd); //test/a.txt

    //打开文件，一个只读，一个写，写位于文件夹中不存在创建
    int fdRead = open("a.txt",O_RDONLY);
    if( fdRead < 0 )
    {
        perror("open");
    }
    int fdWrite = open(fileAdd,O_WRONLY | O_CREAT , 0777);
    if( fdWrite < 0 )
    {
        perror("open");
    }

    while(1)
    {
        char temp[128] = "";
        int len = read(fdRead,temp,sizeof(temp));

        // printf("成功读出%d个数据\n",len);
        // printf("数据为%s\n",temp);
        
        write(fdWrite,temp,len);
        if( len < sizeof(temp) )
            break;
    }

    //关闭文件
    close(fdRead);
    close(fdWrite);
    return 0;
}
