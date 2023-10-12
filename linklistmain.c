#include "linklist.c"
int main()
{
    node *list;
    node H;
    int i;
    char p;
    //初始化单链表
    initlinklist(&H)?printf("初始化成功\n"):printf("初始化失败\n");
    //插入任意数量元素进入链表
    printf("\n请输入你想要插入的元素数量(前插法)\n");
    scanf("%d",&i);
    list = beforeinsert(list,i,&H);
    list == NULL?printf("----插入失败----\n"):printf("----插入成功----\n");
    //输出链表
    printlink(list)?printf("----输出成功----\n"):printf("----输出失败----\n");
    //输出链表的长度
    printf("\n长度为:%d\n",printlen(list));
    //清空链表
    freelist(list)?printf("\n----清空成功----\n"):printf("\n----清空失败----\n");
    //后插法输入任意数量元素进入链表
    printf("\n请输入你想要插入的元素数量(后插法)\n");
    scanf("%d",&i);
    list = afterinsert(list,i,&H);
    list == NULL?printf("----插入失败----\n"):printf("----插入成功----\n");
    //输出链表
    printlink(list)?printf("----输出成功----\n"):printf("----输出失败----\n");
    //输出链表的第i个位置上的元素
    printf("\n请输入想要查找元素的位置:");
    scanf("%d",&i);
    pointi(list,i)?printf("\n----已经完成操作----\n"):printf("\n----执行失败,未找到元素或出现错误----\n");
    //输出元素的位置
    printf("\n请输入想要查找的元素:");
    scanf(" %c",&p);
    printpoint(list,p)?printf("\n----已经完成操作----\n"):printf("\n----执行失败,未找到元素或出现错误----\n");
    //在第i个位置上插入元素
    printf("请输入要插入的位置:");
    scanf("%d",&i);
    printf("\n");
    printf("请输入要插入的元素:");
    scanf(" %c",&p);
    list = intoi(i,p,list);
    list == NULL?printf("----插入失败----\n"):printf("----插入成功----\n");
    //输出插入后的链表
    printf("插入后：\n");
    printlink(list)?printf("----输出成功----\n"):printf("----输出失败----\n");
    //删除链表的第i个元素
    printf("请输入要删除的元素位置：");
    scanf("%d",&i);
    list = deletelist(i,list);
    list == NULL?printf("----删除失败----\n"):printf("----删除成功----\n");
    //输出删除后的链表
    printf("删除后\n");
    printlink(list)?printf("----输出成功----\n"):printf("----输出失败----\n");
    //判断链表是不是空的
    Isempty(list)?printf("\n----链表为空表----\n"):printf("\n----链表不为空----\n");
    //销毁链表
    freelist(list)?printf("\n----销毁成功----\n"):printf("\n----销毁失败----\n");
    return 0;
}