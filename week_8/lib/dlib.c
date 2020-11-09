#include "../ch08.h"

void dynamic_lib_fun_call(void)
{
	printf("Dynamic Lib Fun Called!\n");
}

//应该分输入输出函数分别调用
void sort()
{
    int n,i,j,t,*a;

    printf("Enter the number of integers you want to sort:");
    scanf("%d",&n);//输入待排序元素数量
    a=(int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);//依次输入待排序元素
    }
    //将数组元素从小到大排序
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            {
                t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }

    for(i=0;i<n;i++)//依次输出排序后的元素
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}
