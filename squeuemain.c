#include "squeuedancer.c"
;
int main()
{
    queue Women;
    queue Man;
    Women = InintCreate(Women);
    Man = InintCreate(Man);
    MakeEmpty(Women);
    MakeEmpty(Man);
    for (int i = 0; i < Number; i++)
    {
        if(Dancer[i].sex == 'W')
        {
            EnQueue(Women,Dancer[i].name);
        }
        else
        {
            EnQueue(Man,Dancer[i].name);
        }
    }
    while (!IsEmpty(Women)&&!IsEmpty(Man))
    {
        printf("%s和%s是一组\n",DeQueue(Women),DeQueue(Man));
    }
    if (!IsEmpty(Women))
    {
        printf("下一个等待的是:%s\n",GetHead(Women));
    }
    if (!IsEmpty(Man))
    {
        printf("下一个等待的是:%s\n",GetHead(Man));
    }
    DisposeQueue(Women);
    DisposeQueue(Man);
    return 0;
}