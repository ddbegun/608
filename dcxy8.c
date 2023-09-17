#include <stdio.h>
typedef struct lib
{
int number;
float price;
}
lib;
int main ()
{
lib book;
printf("请输入书号，书名，价格\n");
char str[2][15];
int number[2];
float price[2];
for (int i = 0; i < 2; i++)
{
scanf ("%d",&book.number);
number[i] = book.number;
scanf("%s",str[i]);
scanf("%f",&book.price);
price[i] = book.price;
}
if (price[0]> price[1])
{
printf("价格高的是：%d %s %f\n",number[0],str[0],price[0]);
}
else if (price[1] > price[0])
{
printf("价格高的是：%d %s %f\n",number[1],str[1],price[1]);
}
else
{
printf("%d %s %f\n",number[0],str[0],price[0]);
printf("%d %s %f\n",number[1],str[1],price[1]);
}
return 0;
}

