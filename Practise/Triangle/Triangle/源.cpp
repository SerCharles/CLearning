#include<stdio.h>
int map[101] = { 0 };
int nminus = 0, n = 0;
int main()
{
	int i, j, a;
	map[1] = 1;
	printf("1\n");
	for (i = 2; i <= 10; i++)
	{
		nminus = 0;
		for (j = 1; j <= i; j++)
		{
			a = map[j - 1] + map[j];
			printf("%d ", a);
			map[j - 1] = nminus;
			nminus = a;
		}
		map[i] = a;
		printf("\n");
	}
	while (1);
	return 0;
}