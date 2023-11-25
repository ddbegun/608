#include <stdio.h>
#include <stdlib.h>
#define Maxsize 5 
#define OK 1
#define ERROR 0
typedef int ElementType;
typedef struct sq
{
    int Cap;
    int front;
    int rear;
    int size_q;
    ElementType *data;
}
sq;
typedef sq* queue;
//判断是否为空
int
IsEmpty(queue s)
{
    return s -> size_q == 0;
}
//使空
int
MakeEmpty(queue s)
{
    s -> front = 1;
    s -> rear = 0;
    s -> size_q = 0;
    s -> Cap = Maxsize;
    return OK;
}
//创建队
queue
InintCreate(queue s)
{
    
    s = (sq*)malloc(sizeof(sq));
    if (s == NULL)
    {
        printf("Out of The Space!\n");
        return s;
    }
    s -> data = (ElementType *)malloc(sizeof(ElementType)*Maxsize);
    if (s -> data == NULL)
    {
        printf("Out ofThe Space!\n");
        return NULL;
    }
    return s;
}
//是否为满
int
Isfull(queue s)
{
    return s -> size_q >= s -> Cap;
}
//清空
int
DisposeQueue(queue s)
{
    if (s == NULL)
    {
        printf("EMPTY!\n");
        return ERROR;
    }
    free(s -> data);
    free(s);
    return OK;
}
//循环满
/*
void
Carefull(queue s)
{
    if (s -> front >= Maxsize)
    {
        s -> front = s -> front % Maxsize;
    }
    if( s -> rear >= Maxsize)
    {
        s -> rear = s -> rear % Maxsize;
    }
}
*/
//入队
void
EnQueue(queue s,ElementType e)
{
    if (Isfull(s))
    {
        printf("You Queue Is Full!\n");
        return ;
    }
    int tmp = s -> front;
    s -> data[tmp] = e;
    s -> size_q++;
    s -> front++;
}
//出队
void
DeQueue(queue s)
{
    if(IsEmpty(s))
    {
        printf("You have Error!\n");
        return ;
    }
    int tmp = ++(s -> rear);
    printf("deq:%d\n",s -> data[tmp]);
    s -> size_q--;

}
//大小
void
ShowSize(queue s)
{
    printf("now:%d\n",s -> size_q);
    printf("Max:%d\n",s -> Cap);
}
//取头
ElementType
GetHead(queue s)
{
    return s -> data[s -> size_q];
}