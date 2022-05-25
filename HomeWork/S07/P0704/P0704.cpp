#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
int n, m, list1[1010] = { 0 }, list2[1010] = { 0 };
int ans1[1010] = { 0 }, ans2[2020] = { 0 }, ans3[1010] = { 0 };
int a(int a1[], int a2[]);
int o(int a1[], int a2[]); 
int c(int a1[], int a2[]);
int judge1(int i);
int judge2(int i);
void sort(int l[],int len);
int main()
{
	int i, length1 = 0, length2 = 0, length3 = 0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) scanf("%d", &list1[i]);
	scanf("%d", &m);
	for (i = 1; i <= m; i++) scanf("%d", &list2[i]);
	length1 = a (list1, list2);
	length2 = o (list1, list2);
	length3 = c(list1, list2);
	sort(ans1,length1);
	sort(ans2,length2);
	sort(ans3,length3);
	for (i = 1; i <= length1; i++) printf("%d ", ans1[i]);
	printf("\n");
	for (i = 1; i <= length2; i++) printf("%d ", ans2[i]);
	printf("\n");
	for (i = 1; i <= length3; i++) printf("%d ", ans3[i]);
	return 0;
}
int a(int a1[], int a2[])
{
	int i, j,num=0;
	for (i = 1; i <= n; i++)
	{
		for(j=1;j<=m;j++)
		{
			if (a1[i] == a2[j])
			{
				num++;
				ans1[num] = a1[i];
				break;
			}
		}
	}
	return num;
}
int o(int a1[], int a2[])
{
	int i, num = 0;
	for (i = 1; i <= n; i++)
	{
		num++;
		ans2[num] = a1[i];
	}
	for (i = 1; i <= m; i++)
	{
		if (judge1(i))
		{
			num++;
			ans2[num] = a2[i];
		}
	}
	return num;
}
int c(int a1[], int a2[])
{
	int i, num = 0;
	for (i = 1; i <= n; i++)
	{
		if (judge2(i))
		{
			num++;
			ans3[num] = a1[i];
		}
	}
	return num;
}
int judge1(int i)
{
	int j;
	for (j = 1; j <= n; j++)
	{
		if (list2[i] == list1[j]) return 0;
	}
	return 1;
}
int judge2(int i)
{
	int j;
	for (j = 1; j <= m; j++)
	{
		if (list2[j] == list1[i]) return 0;
	}
	return 1;
}
void sort(int l[],int len)
{
	int i, j;
	for (i = 1; i < len; i++)
	{
		for (j = i + 1; j <= len; j++)
		{
			if (l[i] > l[j])
			{
				int temp = l[i];
				l[i] = l[j];
				l[j] = temp;
			}
		}
	}
}




