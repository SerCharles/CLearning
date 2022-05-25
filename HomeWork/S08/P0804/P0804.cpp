#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char a[1000], b[1000];
int numa[1000] = { 0 }, numb[1000] = { 0 },ans[2000] = { 0 };
int a_length = 0, b_length = 0,num;
void change_c_to_i();
void multiply();
void getans();
int main()
{
	int i;
	change_c_to_i();
	multiply();
	getans();
	for (i = num; i >= 1; i--) printf("%d", ans[i]);
	return 0;
}
void change_c_to_i()
{
	scanf("%s", a);
	scanf("%s", b);
	a_length = strlen(a); b_length = strlen(b);;
	int i;
	for (i = 0; i < a_length; i++)
	{
		numa[a_length - i] = a[i] - 48;
	}
	for (i = 0; i < b_length; i++)
	{
		numb[b_length - i] = b[i] - 48;
	}
}
void multiply()
{
	int i, j;
	for (i = 1; i <= a_length; i++)
	{
		for (j = 1; j <= b_length; j++)
		{
			ans[i + j - 1]+= numa[i] * numb[j];
		}
	}
}
void getans()
{
	int i=1;
	while (1)
	{
		ans[i + 1] += ans[i] / 10;
		ans[i] = ans[i] % 10;
		i++;
		if (ans[i] == 0 && i >= a_length + b_length) break;
	}
	num = i - 1;
}