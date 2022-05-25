#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int maze[5][5] = { 0 };
int visit[5][5] = { 0 };
int movex[5] = { 0,1,-1,0,0 };
int movey[5] = { 0,0,0,1,-1 };
void DFS(int x,int y,int step);
int minstep = 100;
int histx[100] = { 0 };
int histy[100] = { 0 };
int ansx[100] = { 0 };
int ansy[100] = { 0 };
int main()
{
	int i,j;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			scanf("%d", &maze[i][j]);
		}
	}
	DFS(0,0,1);
	for (i = 1; i <= minstep; i++)
	{
		printf("(%d, %d)\n", ansx[i], ansy[i]);
	}
	return 0;
}
void DFS(int x, int y, int step)
{
	int i;
	visit[x][y] = 1;
	histx[step] = x; histy[step] = y;
	if (x == 4 && y == 4)
	{
		if (step < minstep)
		{
			minstep = step;
			memset(ansx, 0, sizeof(ansx));
			memset(ansx, 0, sizeof(ansy));
			for (i = 1; i <= step; i++)
			{
				ansx[i] = histx[i];
				ansy[i] = histy[i];
			}
		}
	}
	else
	{
		for (i = 1; i <= 4; i++)
		{
			int newx = x + movex[i], newy = y + movey[i];
			if (visit[newx][newy] == 0 && maze[newx][newy] == 0&&newx>=0&&newx<5&&newy>=0&&newy<5)
			{
				DFS(newx, newy, step + 1);  //ÐÞ¸Ä
				histx[step + 1] = 0; histy[step + 1] = 0;
				visit[newx][newy] = 0;
			}
		}
	}

}