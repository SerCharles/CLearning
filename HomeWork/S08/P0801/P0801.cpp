#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
int n, m;
int a[15], b[15], result[30] = { 0 },num=1;
void merge(int anum, int bnum);
int main()
{
	scanf("%d", &m);
	int i;
	for (i = 1; i <= m; i++) scanf("%d", &a[i]);
	scanf("%d", &n);
	for (i = 1; i <= n; i++) scanf("%d", &b[i]);
	merge(1, 1);
	for (i = 1; i <= m + n; i++) printf("%d ", result[i]);
	return 0;
}
void merge(int anum, int bnum)
{
	if (a[anum] <= b[bnum]&&anum<=m&&bnum<=n)
	{
		result[num] = a[anum]; 
		num++;
		merge(anum + 1, bnum);
	}
	else if(b[bnum]<a[anum]&&anum <= m&&bnum <= n)
	{
		result[num] = b[bnum];
		num++;
		merge(anum, bnum + 1);
	}
	else if (anum > m&&bnum <= n)
	{
		while (bnum <= n)
		{
			result[num] = b[bnum];
			num++;
			bnum++;
		}
	}
	else if (anum <= m&&bnum > n)
	{
		while (anum <= n)
		{
			result[num] = a[anum];
			num++;
			anum++;
		}
	}
}