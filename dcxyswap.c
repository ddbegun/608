#include <stdio.h>
void swap (int*,int*);
int main()
{
int a,b;
a = 3;
b = 5;
printf("交换前：a = %d,b = %d\n",a,b);

swap(&a,&b);

printf("交换后：a = %d,b = %d\n",a,b);

}
void swap (int *a,int *b)
{
  int tmp = *a;
  *a = *b;
  *b = tmp;

}