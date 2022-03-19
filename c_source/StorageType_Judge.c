#include <stdio.h>

//设计一个程序判断机器的大小都存储
int main()
{
    int a=1;//0x 00 00 00 01

    //用char指针将其地址的第一位取出
    //一个类型的大小和它对应的指针能取到多少字节的数据是对应的
    char *addr=(char*)&a;
    
    //根据第一位是否为1判断大小端字节序
    if(1==*addr)
    {//低位存储在低地址
        printf("当前机器为小端存储");
    }
    else
    {//低位存储在高地址
        printf("当前机器为大端存储");
    }
    getchar();
    return 0;
}