#include "squee.c"

int main(int argv,char *args)
{
    queue s;
    int tmp,e;
    s = InintCreate(s);
    MakeEmpty(s);
    printf("请输入队列大小：\n");
    scanf("%d",&tmp);
    printf("请输入入队元素\n");
    for (int i = 0; i < tmp; i++)
    {
        scanf("%d",&e);
        EnQueue(s,e);
    }
    printf("%d\n",GetHead(s));
    printf("%d\n",IsEmpty(s));
    for(int i = 0; i < tmp; i++)
    DeQueue(s);
    printf("%d\n",DisposeQueue(s));
    return 0;
}