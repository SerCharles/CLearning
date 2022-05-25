#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
int sum;
int number[1010];
void swap(int a, int b)
{
	int temp;
	temp = number[a];
	number[a] = number[b];
	number[b] = temp;
}
void qsort(int head, int tail)
{
	if (head >= tail) return;
	int i = head, j = tail, key = number[head], flag = head;
	while (i<j)
	{
		for (j; j > i; j--)//从右向左，找到第一个比key大的，就交换
		{
			if (number[j] < key)
			{
				swap(j, flag);
				flag = j;
				break;
			}
		}
		for (i; i< j; i++)//从左到右找到第一个比key小的，就交换
		{
			if (number[i] > key)
			{
				swap(i, flag);
				flag = i;
				break;
			}
		}
	}
	qsort(head, i - 1);
	qsort(i + 1, tail);
}
int main()
{
	scanf("%d", &sum);
	int i;
	for (i = 1; i <= sum; i++)
	{
		scanf("%d", &number[i]);
	}
	qsort(1, sum);
	for (i = 1; i <= sum; i++)
	{
		printf("%d ", number[i]);
	}
	return 0;
}