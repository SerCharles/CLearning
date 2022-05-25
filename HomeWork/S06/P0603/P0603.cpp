#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int num,previous;
int handle(int a);
void sort(int a[]);
int main()
{
	scanf("%d", &num);
	while (1)
	{
		previous = num;
		num = handle(num);
		if (num == previous) break;
	}
	printf("%d", num);
	return 0;
}
int handle(int a)
{
	int rank[5];
	rank[1] = a / 1000;
	rank[2] = (a - rank[1] * 1000) / 100;
	rank[4] = a % 10;
	rank[3] = (a - rank[1] * 1000 - rank[2] * 100 - rank[4]) / 10;
	sort(rank);
	int p = rank[1] * 1000 + rank[2] * 100 + rank[3] * 10 + rank[4];
	int q = rank[4] * 1000 + rank[3] * 100 + rank[2] * 10 + rank[1];
	return q - p;
}
void sort(int a[])
{
	int i,j;
	for (i = 1; i <= 3; i++)
	 for(j=i+1;j<=4;j++)
	{
		 if (a[i] > a[j])
		 {
			 int temp = a[i];
			 a[i] = a[j];
			 a[j] = temp;
		}
	}
}