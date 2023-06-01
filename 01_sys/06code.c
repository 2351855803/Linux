#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>



int main(int argc, char const *argv[])
{
    
    //打开目录
    DIR * dir = opendir("./");

    //读取目录文件
    struct dirent* dir_file = NULL;

    //扫描总共有几个.C文件
    int c_count = 0;
    //循环读取
    while(1)
    {
        dir_file = readdir(dir);
        if( NULL == dir_file )
            break;

        //判断文件类型
        if( DT_REG == dir_file->d_type )
            printf("当前文件名为%s,类型为普通文件\n",dir_file->d_name);
        else if( DT_DIR == dir_file->d_type )
            printf("当前文件名为%s,类型为目录\n",dir_file->d_name);

        if( strstr(dir_file->d_name , ".c") )
            c_count++;
        
    }
    printf("该目录中总共存在%d个c文件\n",c_count);




    //关闭目录
    closedir(dir);





    return 0;
}
