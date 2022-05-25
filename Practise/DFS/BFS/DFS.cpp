#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int  num,length,sum;
int startx, starty, endx, endy;
int answer[1010] = { 0 };
int queuex[100100] = { 0 }, queuey[100100] = { 0 },  queueances[100100] = { 0 };
int movex[6] = { 0,1,-1,0,0 };
int movey[6] = { 0,0,0,1,-1 };
int map[110][110] = { 0 };
void DFS(int flag,int group)
{
	if (queuex[flag] == endx&&queuey[flag] == endy) answer[group]=1;
	int i;
	for (i = 1; i <= 4; i++)
	{
		int currentx, currenty;
		currentx = queuex[flag] + movex[i]; currenty = queuey[flag] + movey[i];
		if (currentx >= 0 && currentx < length&&currenty>=0 && currenty < length&&map[currentx][currenty] == 0)
		{
			sum++;
			queuex[sum] = currentx; queuey[sum] = currenty;
			map[currentx][currenty] = 1;
			queueances[sum] = flag;
			DFS(sum,group);
		}
	}
}
int main()
{
	scanf_s("%d", &num);
	int i,j,k;
	for (i = 1; i <= num; i++)
	{
		scanf_s("%d", &length);
		for (j = 0; j < length; j++)
		{
			for (k = 0; k < length; k++)//读入
			{
				scanf_s("%d", &map[j][k]);
			}
		}
		scanf_s("%d%d%d%d", &startx, &starty, &endx, &endy);
		if (map[startx][starty] == 1 || map[endx][endy] == 1)
		{
			answer[i] = 0;
		}
		else
		{
			map[startx][starty] = 1;    //搜索初始化
			queuex[1] = startx; queuey[1] = starty;
			sum = 1;
			DFS(1,i);
		}
		for (j = 0; j < length; j++)  //每组数据后清map
		{
			for (k = 0; k < length; k++)
			{
				map[j][k] = 0;
			}
		}
	}
		for (i = 1; i <= num; i++)  
		{
			if (answer[i] == 1)
			{
				printf("YES\n");
			}
			else
			{
				printf("NO\n");
			}
		}
	
	while (1);
	return 0;
}