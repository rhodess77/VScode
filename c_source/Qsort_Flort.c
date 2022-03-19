#include <stdio.h>
#include <stdlib.h>
//使用qsort函数通过函数指针，对浮点数数组进行排序

int Cmp_Float(const void *e1 , const void *e2)
{
    return *((float*)e1)-*((float*)e2);
}

int main()
{
    float fArr[5]={9.0,5.0,6.0,8.0,7.0};
    int ArrSize = sizeof(fArr)/sizeof(fArr[0]);//求出数组中元素个数
    int ElemSize = sizeof(fArr[0]);
    qsort(fArr,ArrSize,ElemSize,Cmp_Float);
    for(int i=0;i<5;i++)
    {
        printf("%.2f  ",fArr[i]);
    }
    getchar();
    return 0;
}