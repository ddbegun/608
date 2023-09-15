#include <stdio.h>
typedef struct lib
{
 int number;
 char *name;
 int price;

}
lib;

int main()
{
    lib p[2];
    printf("请输入书号，书名，价格\n");
    for (int i = 0; i < 2; i++)
    {
    int number,price;
    char name[10];
    scanf("%d",&number);
    p[i].number = number; 
    scanf("%s",name);
    p[i].name = name; 
    scanf("%d",&price);
    p[i].price = price; 
    }
    if (p[0].price > p[1].price)
    {
        printf("价格较高的书是：%d %s %d\n",p[0].number,p[0].name,p[0].price);
    }
    else if (p[0].price < p[1].price)
    {
         printf("价格较高的书是：%d %s %d\n",p[1].number,p[1].name,p[1].price);
    }
    else
    {
         printf("%d %s %d\n",p[1].number,p[1].name,p[1].price);
         printf("%d %s %d\n",p[0].number,p[0].name,p[0].price);
    }
    }
    
    
    


