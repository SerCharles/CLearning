#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
int n;
int num[20];
void qsort(int head, int tail)
{
	int mid = num[head];
	int h = head, t = tail;
	if (head >= tail) return;
	while (h < t)
	{
		while (num[t] >= mid&&t>h) t--;
		if (t>h)
		{
			num[h] = num[t];
			h++;
		}
		while (num[h] <= mid&&t>h) h++;
		if (t>h)
		{
			num[t] = num[h];
			t--;
		}
	}
	num[h] = mid;
	qsort(head, h - 1);
	qsort( t + 1,tail);
}
int main()
{
	scanf("%d", &n);
	int i;
	for (i = 1; i <= n; i++) scanf("%d", &num[i]);
	qsort(1, n);
	for (i = 1; i <= n; i++) printf("%d ", num[i]);
	while (1);
	return 0;
}