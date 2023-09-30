#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXSIZE 100
#define MORESIZE 150
typedef char elemtype;
typedef struct sqlist
{
elemtype *name;
int length;
}
sqlist;
//初始化顺序表
int initlist(sqlist *L) 
{
  L -> name =(elemtype*) malloc(MAXSIZE * sizeof(sqlist));
  if (!L -> name)
  {
        printf("出错啦！请检查内存\n");
        return 1;
  }
  L -> length = 0;
  return 0;
}
//创建顺序表
int createlist(sqlist *L)
{
    int n;
    printf("\n请输入要创建的元素个数\n");
    scanf("%d",&n);
    printf("请输入要创建的元素\n");
    for (int i = 0; i < n; i++)
    {
        scanf(" %c",&L -> name[i]);
        L -> length += 1;
    }
    return 1;
}
//输出顺序表
int printflist(sqlist L)
{
    printf("\n输出顺序表的元素为：\n");
    for(int i = 0;i < L.length;i++)
    {
      printf("%c\n",L.name[i]);
    }
    return 1;
}
//输出顺序表的长度
void printlength(sqlist L)
{
    printf("\n顺序表的长度为：%d\n", L.length);
}
//判断顺序表是否为空
int isempty(sqlist L)
{
    if (L.length == 0)
    {
      return 0;
    }
    return 1;
}
//输出顺序表第i个位置的元素
elemtype pointi(int i,sqlist L)
{
  if(i > L.length || i < 0)
  {
      printf("没有这样的元素存在\n");
      return '0';
  }
  return L.name[i-1];
}
//输出数据元素n
elemtype printgroupn(char n,sqlist L)
{
    for(int i = 0; i < L.length; i++) 
    {
        if (L.name[i] == n)
        {
          return L.name[i];
        }
    }
    printf("该顺序表里不存在这样的数据元素\n");
    return '0';
}
//在第i个位置上插入元素n
int insertlist(int i,char n,sqlist *L)
{
    if (i > MAXSIZE)
    {
      sqlist * p =(sqlist*)realloc(L,MORESIZE * sizeof(sqlist));
      L = p;
    }
    else if(i < 0)
    {
        printf("error!这个位置上不能插入元素\n");
        return 1;    
    }
    for (int tmp = L -> length;tmp > i - 1; tmp--)
    {
        L -> name[tmp] = L -> name[tmp - 1];
    }
    L -> name[i - 1] = n;
    L -> length += 1;
    return 0;
}
int deletelist(int i,sqlist *L)
{
    if (i > L -> length)
    {
      printf("\n这个位置上没有元素\n");
      return 0;
    }
    for(int tmp = i; tmp < L -> length; tmp++)
    {
       L -> name[tmp - 1]  =  L -> name[tmp]; 
    }
    L -> length -= 1;
    return 1;
}
//free顺序表
int freelist(sqlist *L)
{
   if (!L -> name)
   {
      printf("empty!\n");
      return 1;
   }
   free(L -> name);
   return 0;
}


