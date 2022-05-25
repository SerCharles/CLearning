#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char fifteen[10];
int shiwu[10], seven[10] = { 0 };
int ten=0,s=0;
void getseven(int num)
{
s++;
seven[s] = num % 7;
if (num / 7) getseven(num / 7);
}
int square(int num)
{
int i;
int sum = 1;
for (i = 1; i <= num; i++)
{
sum = sum * 15;
}
return sum;
}


int main()
{
int i;
scanf("%s",fifteen);
for (i = 0; i <3; i++)
{
if (fifteen[i] < 60)  shiwu[i] = fifteen[i] - 48;
else shiwu[i ] = fifteen[i] - 55;
}
for (i = 0; i <=2; i++)
{
ten = ten + shiwu[i] * square(2-i);
}
getseven(ten);
for (i = 4; i >= 1; i--)
{
printf("%d", seven[i]);
}
return 0;
}