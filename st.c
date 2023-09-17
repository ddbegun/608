#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
int x;
printf("请输入书本的个数\n");
scanf("%d",&x);
char str[x][14];
printf("请输入书本的名字\n");
for (int i = 0; i < x; i++)
{
scanf ("%s",str[i]);
}
char name[14];
printf("请输入你想要找的书\n");
scanf ("%s",name);
for (int i = 0; i < x; i++)
{
int tmp = strcmp(name,str[i]);
if (tmp == 0)
{
printf("found\n");
break;
}
else if (tmp != 0 && i == x - 1)
{
printf("not found\n");
}
}
return 0;
}
