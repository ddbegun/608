#include<stdio.h>
#include<stdlib.h>
typedef int elemtype;
typedef struct node
{
    elemtype elem;
    struct node *next;

}
node;
//初始化链表
elemtype initlinklist(node *H)
{
    H = malloc(sizeof(node));
    H -> next = NULL;
    return 1;
}
//合并链表(有重复)
int meragelist(node *La,node * Lb)
{
    node *Lc = NULL;
    node *tma = La;
    node *tmb = Lb;
    if (tma -> elem < tmb -> elem)
    {
        Lc = tma;
        tma = tma -> next;
    }
    else if (tma -> elem > tmb -> elem)
    {
        Lc = tmb;
        tmb = tmb -> next;
    }
    else
    {
        Lc = tma;
        tma = tma -> next;
        Lc -> next = tmb;
        Lc = tmb;
        tmb = tmb -> next;
    }
    while (tma != NULL && tmb != NULL)
    {
        if (tma -> elem > tmb -> elem)
        {
            Lc -> next = tmb;
            Lc = tmb;
            tmb = tmb -> next;
        }
        else
        {
            Lc -> next = tma;
            Lc = tma;
            tma = tma -> next;
        }
    }
    if (tma == NULL)
    {
        Lc -> next = tmb;
        return 1;
    }
    else
    {
        Lc -> next = tma;
        return 0;
    }
}
//合并链表（没有重复）
int meragelist2(node *La,node *Lb)
{
    node *Lc = NULL;
    node *tma = La;
    node *tmb = Lb;
    if (tma -> elem < tmb -> elem)
    {
        Lc = tma;
        tma = tma -> next;
    }
    else
    {
        Lc = tmb;
        tmb = tmb -> next;
    }
    while (tma != NULL && tmb != NULL)
    {
        if (tma -> elem > tmb -> elem)
        {
            Lc -> next = tmb;
            Lc = tmb;
            tmb = tmb -> next;
        }
        else if (tma -> elem < tmb -> elem)
        {
            Lc -> next = tma;
            Lc = tma;
            tma = tma -> next;
        }
        else
        {
            node *new = NULL;
            Lc -> next = tma;
            Lc = tma;
            tma = tma -> next;
            new = tmb -> next;
            free(tmb);
            tmb = new;
        }
    }
    if (tma == NULL)
    {
        Lc -> next = tmb;
        return 1;
    }
    else
    {
        Lc -> next = tma;
        return 0;
    }
}
//逆序输出
void verse(node *p)
{
    if (p -> next == NULL || p == NULL)
    {
        printf("%d\n",p -> elem);
        return ;
    }
    verse(p -> next);
    printf("%d\n",p -> elem);
}
//前插法插入任意个数据元素
node* beforeinsert(node *list,int i,node *H)
{
    list = NULL;
    elemtype x;
    printf("请输入要插入的元素\n");
    for (int tmp = 0;tmp < i;tmp++)
    {
       H = malloc(sizeof(node));
       if (!H)
       {
        printf("出错啦！");
        return NULL;
       }
       scanf("%d",&x); 
       H -> elem = x;
       H -> next = NULL;
       if(list == NULL)
       {
        list = H;
       }
       else
       {
       for (node *tmp = list;tmp != NULL;tmp = tmp -> next)
       {
        if (tmp -> next == NULL)
            {
                tmp -> next = H;
                break;
            }
       }
       }
    }
    return list;
}

//输出单链表
int printlink(node *list)
{
    node *tmp = NULL;
    for (tmp = list;tmp != NULL;tmp = tmp -> next)
    {
        printf("%d\n",tmp -> elem);
    }
    return 1;
}
//输出单链表的长度
int printlen(node *list)
{
    int len = 0;
   for (node *tmp = list;tmp != NULL;tmp = tmp -> next) 
   {
    len += 1;
   }
   return len;
}
//后插法插入任意元素
node *afterinsert(node *list,int i,node *H)
{
    list = NULL;
    elemtype x;
    printf("请输入要插入的元素\n");
    for (int tmp = 0; tmp < i; tmp++) 
    {
        H = malloc(sizeof(H));
        if (!H)
        {
            printf("出错啦!\n");
            return NULL;
        }
        scanf("%d",&x);
        H -> elem = x;
        H -> next = NULL;
        H -> next = list;
        list = H;
    }
    return list;
}
//输出链表i位置的元素
int pointi(node *list,int i)
{
    int cell = 0;
    for (node *tmp = list; tmp != NULL; tmp = tmp -> next)
    {
        cell += 1;
        if (cell == i)
        {
            printf("该位置上的元素为：%d",tmp -> elem);
            return 1;
        }
    }
    return 0;
}
//输出元素位置
int printpoint(node *list,elemtype i)
{
    int x = 0;
    for (node *tmp = list;tmp != NULL; tmp = tmp -> next)
    {
       x += 1;
       if (i == tmp -> elem) 
       {
        printf("该元素在%d个位置上",x);
        return 1;
       }
    }
    return 0;
}
//在第i个位置上插入元素
node* intoi(int i,elemtype n,node *list)
{
    int x = 1;
    node *tmpcell = malloc(sizeof(node));
    for (node *tmp = list; tmp != NULL; tmp = tmp -> next)
    {
        if (x == i-1)
        {
            tmpcell -> next = tmp -> next;
            tmp -> next = tmpcell;
            tmpcell -> elem = n;
            return list;
        }
        x++;

    }
    return NULL;

}
//删除链表指定位置的元素
node* deletelist(int i,node *list)
{
    int j = 1;
    node *tmp = NULL;
    for (tmp = list;tmp != NULL;tmp = tmp -> next)
    {
        if (i != 1&&j == i - 1)
        {
           node *cell = tmp -> next -> next;
           free(tmp -> next); 
           tmp -> next = cell;
           return list;
        }
        else if(i == 1)
        {
            node *cell = tmp -> next;
            free(tmp);
            tmp = cell;
            return tmp;
        }
        j++;
    }
    return NULL;
}
//判断链表是不是为空
int Isempty(node *list)
{
    return list == NULL;
}
//销毁链表&&清空链表
elemtype freelist(node *list)
{
    node *tmp = list;
    while (tmp != NULL)
    {
        node *new = tmp -> next;
        free(tmp);
        tmp = new;
        }
    return 1;
}





