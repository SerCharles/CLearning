#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
int n;
int a[300];
void qsort(int left, int right);
int main()
{
	scanf("%d", &n);
	for (int i=1; i <= n; i++) scanf("%d", &a[i]);
	qsort(1, n);
	for (int i=1; i <= n; i++) printf("%d ", a[i]);
	return 0;
}
void qsort(int left, int right)
{
	int inileft = left, iniright = right;
	int value = a[left];
	if (left >= right) return;
	do
	{
		while (a[right] >= value&&right>left)
		{
			right--;
		}
		if (right>left)
		{
			a[left] = a[right];
			left++;
		}
		while (a[left] <= value&&left<right)
		{
			left++;
		}
		if (right>left)
		{
			a[right] = a[left];
			right--;
		}
	} while (left != right);
	a[left] = value;
	qsort(inileft, left - 1);
	qsort(left + 1, iniright);
}