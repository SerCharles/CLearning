#include <stdio.h>
#include <stdlib.h>
int num, start, end, t;
int queueplace[1000100] = { 0 }, queuestep[1000100] = { 0 }, queuejudge[1001000] = { 0 };
int answer[22] = { 0 };
int handle(int head, int mod)
{
	if (mod == 1) return  queueplace[head] + 1;
	if (mod == 2) return  queueplace[head] - 1;
	if (mod == 3) return  queueplace[head] * 2;
	if (mod == 4 && queueplace[head] % 2 == 0) return queueplace[head] / 2;
}
int BFS()
{
	int head = 1, tail = 1,i;
	queueplace[head] = start; queuestep[head] = 0; queuejudge[start] = 1;
	t = start;
	if (t < end) t = end;
	while (head <= tail)
	{
		for (i = 1; i <= 4; i++)
		{
			if (queueplace[tail] == end)   return queuestep[tail] * 2;
			int current = handle(head, i);
			if (current > 0 && current < 1000000 && queuejudge[current] == 0)
			{
				tail++;
				queueplace[tail] = current;
				queuestep[tail] = queuestep[head] + 1;
				queuejudge[current] = 1;
				if (current > t) t = current;
			}
		}
		head++;
	}
	
}
int main()
{
	scanf_s("%d", &num);
	int i;
	for (i = 1; i <= num; i++)
	{
		scanf_s("%d%d", &start, &end);
		answer[i] = BFS();
		int j;
		for (j = 1; j <= t; j++)		queuejudge[j] = 0;
	}
	for (i = 1; i <= num; i++) printf("%d\n", answer[i]);
	while (1);
	return 0;
}