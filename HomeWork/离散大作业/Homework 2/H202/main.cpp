//£¡>&>|>^>~
#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char name[100], c;
int map[20][50000] = { 0 };
char ans1[1001] = { '\0' }, ans2[1001] = { '\0' };
int length = -1, num1 = 0, num2 = 0;
int main()
{
	while (1)
	{
		scanf("%c", &c); //scan and get the elements
		if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		{
			length++;
			name[length] = c;
		}
		if (c == '\n') break;
	}
	length--;
	int i, j, l = 1;
	for (i = 1; i <= length; i++) l = l * 2;

	for (j = 1; j <= l; j++)
	{
		for (i = 0; i <= length; i++)
		{
			scanf("%d", &map[i][j]);
		}
	}
	for (i = 1; i <= l; i++)//handle the diagram
	{
		if (map[length][i] == 1)
		{
			if (num1)
			{
				num1++;
				ans1[num1] = '|';
			}
			num1++;
			ans1[num1] = '(';
			for (j = 0; j < length; j++)
			{
				if (j)
				{
					num1++;
					ans1[num1] = '&';
				}
				if (map[j][i] == 1)
				{
					num1++;
					ans1[num1] = name[j];
				}
				else
				{
					num1 = num1 + 2;
					ans1[num1 - 1] = '!';
					ans1[num1] = name[j];
				}
			}
			num1++;
			ans1[num1] = ')';
		}
		if (map[length][i] == 0)
		{
			if (num2)
			{
				num2++;
				ans2[num2] = '&';
			}
			num2++;
			ans2[num2] = '(';
			for (j = 0; j < length; j++)
			{
				if (j)
				{
					num2++;
					ans2[num2] = '|';
				}
				if (map[j][i] == 0)
				{
					num2++;
					ans2[num2] = name[j];
				}
				else
				{
					num2 = num2 + 2;
					ans2[num2 - 1] = '!';
					ans2[num2] = name[j];
				}
			}
			num2++;
			ans2[num2] = ')';
		}
	}
	if (num1 <= 7)
	{
		for (i = 2; i <= num1 - 1; i++)
		{
			printf("%c", ans1[i]);
		}
	}
	else
	{
		for (i = 1; i <= num1; i++)
		{
			printf("%c", ans1[i]);
		}
	}
	printf("\n");
	if (num2 <= 7)
	{
		for (i = 2; i <= num2 - 1; i++)
		{
			printf("%c", ans2[i]);
		}
	}
	else
	{
		for (i = 1; i <= num2; i++)
		{
			printf("%c", ans2[i]);
		}
	}
	return 0;
}