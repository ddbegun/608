#include <stdio.h>
#include <stdlib.h>
int main()
{
    int m;
    printf("请输入整数\n"); 
    scanf ("%d",&m);
    //申请m*4个字节的内存
    int *n = malloc(m*sizeof(int));
    printf("请输入%d个数字\n",m);
    //将输入的整数存到申请的内存中
    for (int i = 0; i<m; i++)
    {
        int tmp;
        scanf("%d",&tmp);
        n[i] = tmp;
    }
    //利用选择排序法将输入的整数排序
    for (int i = 0;i < m; i++)
    {
     for (int j = i+1;j < m; j++)
     {
         if (n[i] > n[j])
         {
            int tmp = n[i];
            n[i] = n[j];
            n[j] = tmp;
         }
         
     }

    }
    //输出排序后的数组
    printf("排序后:\n");
    for (int i = 0; i<m; i++ )
    {
        printf("%d ",n[i]);
    
    }
    //清空申请的内存
    free (n);
    return 0;
}