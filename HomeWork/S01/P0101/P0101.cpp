#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
int main()
{
	float sale, rate;
	float tax;
	scanf("%f%f", &sale, &rate);
	tax = sale*rate;
	printf("%0.2f", tax);
	return 0;
}