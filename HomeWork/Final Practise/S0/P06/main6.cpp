#define _CRT_NONSTDC_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdio.h>
char str[100], length[70];
int l, n, ans = 0;
char dict[70][70] = { 0 };
int visit[70] = { 0 };
void DFS(int place);
int compare(int one, int place);
int main()
{
	scanf("%s", str);
	l = strlen(str);
	scanf("%d", &n);
	int i;
	for (i = 1; i <= n; i++)
	{
		scanf("%s", dict[i]);
		length[i] = strlen(dict[i]);
	}
	DFS(0);
	printf("%d", ans);
	return 0;
}
void DFS(int place)
{
	if (place == l)
	{
		ans++;
	}
	else
	{
		int i;
		for (i = 1; i <= n; i++)
		{
			if (compare(i, place))
			{
				place += length[i];
				DFS(place);
				place -= length[i];
			}
			
		}
	}

}
int compare(int one, int place)
{
	int ll = length[one];
	int i;
	for (i = 0; i < ll; i++)
	{
		if (dict[one][i] != str[place + i]) return 0;
	}
	return 1;
}