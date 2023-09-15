#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct lib
{
    char *name;
}
lib;

int main()
{
  int x;
  printf("请输入书的个数\n");
  scanf ("%d",&x);
  lib p[x];
  for (int i = 0; i<x; i++)
  {
    char *s[10];
    scanf("%s",s);
    p[i].name = s;
  }
  printf("请输入要找的书:\n");
  char *id[10];
  scanf ("%s",id);
  for (int i = 0; i<x; i++)
  {
   int re = strcmp(id,p[i].name);
   if (re == 0)
   {
    printf("found\n");
    break;
   }
   else
   {
    printf("not found\n");
   }
  }
    return 0;
}