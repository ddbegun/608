#include "sqlist.c"
int main()
{
   int i;
   char tmp;
   char n;
   sqlist L;
   //初始化顺序表
   initlist(&L)?printf("\n----不能执行操作----\n"):printf("----初始化成功----\n");
   //创建顺序表
   createlist(&L)?printf("----创建顺序表成功----\n"):printf("----创建失败----\n");
   //输出顺序表
   printflist(L)?printf("----输出顺序表成功----\n"):printf("----输出顺序表失败----\n");
   //输出顺序表的长度
   printlength(L);
   //判断顺序表是不是空
   isempty(L)?printf("\n该顺序表不是空表\n"):printf("\n该顺序表是空表\n");
   //输出第i个位置的元素
   printf("\n请输入想查找的数据元素的位置:");
   scanf("%d",&i);
   tmp = pointi(i,L);
   if(tmp != '0')
   printf("第%d个位置的元素为：%c\n",i,tmp);
   //输出数据元素n
   printf("\n请输入想查找数据元素:\n");
   scanf(" %c",&n);
   tmp = printgroupn(n,L);
   if(tmp != '0')
   printf("存在该数据元素%c\n",tmp);
   //在顺序表第i个位置上插入元素n
   printf("\n请输入要在哪个位置上插入元素:");
   scanf("%d",&i);
   printf("请输入要插入的元素:");
   scanf(" %c",&n);
   insertlist(i,n,&L)?printf("\n----插入失败----\n"):printf("\n----插入成功----\n");
   //输出顺序表
   printflist(L)?printf("----输出顺序表成功----\n"):printf("----输出顺序表失败----\n");
   //删除顺序表中的某个元素
   printf("请输入要删除的元素的位置:\n");
   scanf("%d",&i);
   deletelist(i,&L)?printf("----删除成功----"):printf("----删除失败----");
   //输出顺序表
   printf("\n删除元素后:");
   printflist(L)?printf("----输出顺序表成功----\n"):printf("----输出顺序表失败----\n");
   //清空顺序表
   freelist(&L)?printf("\n----不能执行操作----\n"):printf("\n----顺序表已经清空----\n");
   return 0;
}