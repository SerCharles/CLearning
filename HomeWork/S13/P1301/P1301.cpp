#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxm 100000
#define maxvalue 1000000
int map[maxm+1] = { 0 };
int visit[maxm + 1] = { 0 };
int list[maxm + 1] = { 0 };
int n, k;
void bfs(int start);
int main()
{
	scanf("%d%d", &n, &k);
	int i;
	for (i = 0; i <= maxm; i++) map[i] = maxvalue;
	bfs(n);
	printf("%d", map[k]);
	return 0;
}
void bfs(int start)
{
	map[start] = 0;
	visit[start] = 1;
	int head = 1,tail = 1;
	list[head] = start;
	while (head <= tail)
	{
		int i;
		int a = list[head];
		for (i = 1; i <= 3; i++)
		{
			
			if (i == 1&&a+1<=maxm&&visit[a+1]==0)
			{
				tail++;
				visit[a+ 1] = 1;
				map[a + 1] = map[a] + 1;
				list[tail] = a + 1;
			}
			if (i == 2 && a -1 >= 0&&visit[a -1] == 0)
			{
				tail++;
				visit[a-1] = 1;
				map[a -1] = map[a] + 1;
				list[tail] = a -1;
			}
			if (i == 3 && a * 2 <= maxm&&visit[2 * a] == 0)
			{
				tail++;
				visit[2 * a] = 1;
				map[2 * a] = map[a] + 1;
				list[tail] = 2 * a;
			}
			
		}
		head++;
	}
}