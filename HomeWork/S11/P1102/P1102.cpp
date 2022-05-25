#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
FILE *fin1 = NULL;
FILE *fout = NULL;
FILE *fin2 = NULL;
int num = 0;
int list[30], ans[30] = { 0 };
void qsort(int head, int tail);
int main()
{
	fin1 = fopen("data2.txt", "r");
	fout = fopen("dataout.txt", "w");
	
	while (!feof(fin1))
	{
		int a;
		fscanf(fin1, "%d", &a);
		num++;
		list[num] = a;
	}
	int i;
	qsort(1, num);
	for (i = 1; i <= num; i++)
	{
		fprintf(fout, "%d ", list[i]);
	}
	
	fclose(fin1); fclose(fout);
	fin2 = fopen("dataout.txt", "r");
	for (i = 1; i <= num; i++)
	{
		fscanf(fin2, "%d ", &ans[i]);
	}
	for (i = 1; i <= num; i++)
	{
		printf("%d ", ans[i]);
	}
	fclose(fin2);
	return 0;
}
void qsort(int head, int tail)
{
	int value = list[head];
	int t = tail, h = head;
	if (h >= t) return;
	while (h<t)
	{
		while (list[t] >= value&&t>h)
		{
			t--;
		}
		if (t > h)
		{
			list[h] = list[t]; h++;
		}
		while (list[h] < value&&h<t)
		{
			h++;
		}
		if (t > h)
		{
			list[t] = list[h]; t--;
		}
	}
	list[h] = value;
	qsort(t + 1, tail);
	qsort(head, t - 1);
	
}