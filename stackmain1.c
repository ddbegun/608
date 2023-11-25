#include "stackarry.c"
int main()
{
    stack s;
    int size_s;
    int tmp;
    printf("请输入要输入栈的大小\n");
    scanf("%d",&size_s);
    s = createstack(size_s);
    MakeEmpty(s);
    printf("请输入栈的元素:\n");
    for (int i = 0; i < size_s; i++)
    {
        scanf("%d",&tmp);
        push(tmp,s);
    }
    ReturnTop(s);
    Isempty(s);
    for (int i = 0; i < size_s; i++)
    {
        pop(s);
    }
    printf("请输入要转化的十进制数:\n");
    scanf("%d",&tmp);
    conversion(tmp,s);
    printf("八进制为：\n");
    while (!Isempty(s))
    {
        pop(s);
    }
    
    Disposestack(s);

    return 0;
}