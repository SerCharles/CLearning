#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
int type;
double income, tax,limit;
double getlimit()
{
	if (type == 1) return 17850;
	if (type == 2) return 23900;
	if (type == 3) return 29750;
	if (type == 4) return 14875;
}
int main()
{
	scanf("%d%lf", &type, &income);
	limit = getlimit();
	if (income <= limit) tax = income*0.15;
	else tax = limit*0.15 + (income - limit)*0.28;
	printf("%0.6f", tax);
	return 0;
}