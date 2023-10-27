#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXSIZE 100
#define MORESIZE 150
typedef int elemtype;
typedef struct sqlist
{
int *name;
int length;
}
sqlist;
//初始化顺序表
int initlist(sqlist *L) 
{
  L -> name =(elemtype*) malloc(MAXSIZE * sizeof(elemtype));
  if (!L -> name)
  {
        printf("出错啦！请检查内存\n");
        return 1;
  }
  L -> length = 0;
  return 0;
}
//合并有序顺序表
int meragesqlist1(sqlist *La,sqlist *Lb,sqlist *Lc)
{
  int lena = La -> length;
  int lenb = Lb -> length;
  int lenc = lena + lenb;
  Lc -> name =(int*)malloc(sizeof(int) * lenc);
  Lc -> length = lenc;
  int *tma = La -> name;
  int *lasta = tma + lena; 
  int *tmb = Lb -> name;
  int *lastb = tmb + lenb;
  int *tmc = Lc -> name;
  while (tma != lasta && tmb != lastb)
  {
    if (*tma >= *tmb)
    {
      *tmc++ = *tmb++;
    }
    else
    {
      *tmc++ = *tma++;
    }
  }
  if (tma != lasta)
  {
    *tmc++ = *tma++;
  }
  else
  {
    *tmc++ = *tmb++;
  }
  return 1; 
}
//实现合并
int meragesqlist2(sqlist *La,sqlist *Lb,sqlist *Lc)
{
  int lena = La -> length;
  int lenb = Lb -> length;
  int lenc = lena + lenb;
  Lc -> name =(int*)malloc(sizeof(int) * lenc);
  Lc -> length = lenc;
  int *tma = La -> name;
  int *lasta = tma + lena; 
  int *tmb = Lb -> name;
  int *lastb = tmb + lenb;
  int *tmc = Lc -> name;
  while (tma != lasta && tmb != lastb)
  {
    if (*tma > *tmb)
    {
      *tmc++ = *tmb++;
    }
    else if(*tma < *tmb)
    {
      *tmc++ = *tma++;
    }
    else
    {
      *tmc++ = *tma++;
      tmb++;
      Lc -> length -= 1;
    }
  }
  if (tma != lasta)
  {
    *tmc++ = *tma++;
  }
  else
  {
    *tmc++ = *tmb++;
  }
  return 1; 
}
//实现线性表的合并
int meragesqlist(sqlist *La,sqlist *Lb)
{
  int len1 = La -> length;
  int len2 = Lb -> length;
  int *p1;
  int *p2;
  for (p2 = Lb -> name;p2 != Lb -> name + len2; p2++)
  {
    for (p1 = La -> name;p1 != La -> name + len1; p1++)
    {
      if (*p1 == *p2)
      {
       break; 
      }
    }
    if (p1 == La -> name + len1)
    {
        *p1 = *p2;
        La -> length += 1;
        len1 += 1;
    }
  }
  return 1;
}
int verse(sqlist* Lc)
{
    int len = Lc -> length;
    for (int i = 0; i < len / 2; i++)
    {
      int tmp = Lc -> name[i];
      Lc -> name[i] = Lc -> name[len - 1 -i];
      Lc -> name[len - 1 - i] = tmp;
    }
    return 1;
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
        scanf("%d",&L -> name[i]);
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
      printf("%d\n",L.name[i]);
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


