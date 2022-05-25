/*#include<stdio.h>
#include<stdlib.h>
int scene, length;
int startx, starty, endx, endy,time;
int answer[1000] = { 0 };
int queuex[100100] = { 0 }, queuey[100100] = { 0 }, queuestep[100100] = { 0 };
int hash[320][320] = { 0 };
int movex[10] = { 0,2,2,-2,-2,1,1,-1,-1 };
int movey[10] = { 0,1,-1,1,-1,2,-2,2,-2 };
int BFS()
{
	int head = 1, tail = 1;
	queuex[1] = startx; queuey[1] = starty;
	hash[startx][starty] = 1;
	queuestep[1] = 0;
	if (startx == endx&&starty == endy) return 0;
	while (head <= tail)
	{
		int i;
		for (i = 1; i <= 8; i++)
		{
			if (queuex[head] + movex[i] >= 0 && queuex[head] + movex[i] < length&&queuey[head] + movey[i] >= 0 && queuey[head] + movey[i] < length)
			{
				int currentx = queuex[head] + movex[i], currenty = queuey[head] + movey[i];
				if (currentx == endx&&currenty == endy)
				{
					time = tail;
					return queuestep[head] + 1;
				}
				else if (hash[currentx][currenty] == 0)
				{
					tail++;
					queuex[tail] = currentx; queuey[tail] = currenty; queuestep[tail] = queuestep[head] + 1;
					hash[currentx][currenty] = 1;
				}

			}
		}
		head++;
	}
}
int main()
{
	scanf_s("%d", &scene);
	int i, j, k;
	for (i = 1; i <= scene; i++)
	{
		scanf_s("%d", &length);
		scanf_s("%d%d", &startx, &starty);
		scanf_s("%d%d", &endx, &endy);
		answer[i] = BFS();
		for (j = 0; j < length; j++)
		{
			for (k = 0; k < length; k++)
			{
				hash[j][k] = 0;
			}
		}
		for (j = 1; j <= time; j++)
		{
			queuex[j] = 0;
			queuey[j] = 0;
			queuestep[j] = 0;
		}
	}
	for (i = 1; i <= scene; i++)
	{
		printf("%d\n", answer[i]);
	}
	while (1);
	return 0;
}*/