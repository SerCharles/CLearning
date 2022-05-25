#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<vector>
using namespace std;
struct ch
{
	char word;
	int time;
};
char c1[110];
int visit1[60] = { 0 };
vector <ch> visit;
int main()
{
	char c;
	int i,j;
	gets(c1);
	for (j=0;j<strlen(c1);j++)
	{
		c = c1[j];
		int v = 0;
		for (i = 0; i < visit.size(); i++)
		{
			if (c == visit[i].word)
			{
				visit[i].time++;
				v = 1;
				break;
			}
		}
		if (v == 0)
		{
			ch q;
			q.word = c; q.time = 1;
			visit.push_back(q);
		}
	}
	for (i = 0; i < visit.size(); i++)
	{
		if (visit[i].time % 2 != 0)
		{
			printf("%c", visit[i].word);
		}
	}
	return 0;
}





