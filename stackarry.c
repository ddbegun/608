#include <stdio.h>
#include <stdlib.h>

#define Maxsize 100
#define Minsize 3
#define EmptyTOS -1

typedef int element;
typedef struct stackarray
{
    element capacity;
    element top;
    element *Array;
}stackarray;
typedef stackarray* PtrToNode;
typedef PtrToNode stack;

//使空
void
MakeEmpty(stack s)
{
    s -> top = EmptyTOS;
}
//创建栈
stack
createstack (int maxsize)
{
    stack s;
    if (maxsize < Minsize)
    {
        printf("to small!\n");
    }
    s = (stackarray*)malloc(sizeof(stackarray));
    if (s == NULL)
    {
        printf("out of the spacce!\n");
        return s;
    }
    s -> Array = (element*)malloc(sizeof(element)*Maxsize);
    if (s -> Array == NULL)
    {
        printf("out of the space!\n");
        return NULL;
    }
    s -> capacity = maxsize;

    return s;
}
//释放栈
void
Disposestack(stack s)
{
    if (s != NULL)
    {
        free(s -> Array);
        free(s);
    }
}
//判断空
int
Isempty(stack s)
{
    return s -> top == EmptyTOS;
}

//判断满
int 
Isfull(stack s)
{
    return s -> top == s -> capacity;
}

//进栈
void
push(element x,stack s)
{
    if (Isfull(s))
    {
        printf("full!\n");
    }
    else
    s -> Array[++(s -> top)] = x;
}
//返回栈顶
element
ReturnTop(stack s)
{
    if(Isempty(s))
    {
        printf("error!\n");
        return 0;
    }
    return s -> Array[s -> top];
}
//出栈
void
pop(stack s)
{
    if(Isempty(s))
    {
        printf("erorr!\n");
    }
    printf("%d \n",s -> Array[s -> top]);
    s -> top--;
}

//出栈和弹出
element
PopAndTop(stack s)
{
    if (Isempty(s))
    {
        printf("error!\n");
        return 0;
    }
    printf("%d\n",s -> Array[s -> top]);
    s -> top--;
    return s -> Array[s -> top];
}
//转化
void
conversion(int number,stack s)
{
    while (number%8 != 0)
    {
        push(number%8,s);
        number = number / 8;
    }
    
}

