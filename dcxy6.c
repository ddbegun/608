#include <stdio.h>
void inverse(int *,int);
int main()
{
    int x;
    printf("请输入个数");
    scanf ("%d",&x);
    int m[x];
    printf("请输入%d个数",x);
    for (int i = 0; i < x; i++)
    {
            int tmp;
         scanf("%d",&tmp);
         m[i] = tmp;
    }
    inverse(m,x);
    printf("排序后\n");
    for (int i = 0; i < x; i++)
    {

        printf("%i ",m[i]);
    }

return 0;
}
void inverse(int *a,int len)
{
   for (int i = 0; i < len; i++) 
   {
      for (int j = i + 1;j < len;j++)
      {
          if (a[i] < a[j])
          {
            int tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
          }
      }
   }
}