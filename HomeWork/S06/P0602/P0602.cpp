#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char left[110], right[110] = { 0 };
char ch[110];
char ini;
int num1 = 0, num2 = 0;
void sortleft(int i);
void sortright(int i);
void swapsort(char a,int length);
int main()
{
	char c;
	int i;
	gets(ch);
	ini = ch[0];
	for (i = 1; i < strlen(ch); i++)
	{
		if (ch[i] > ini) sortleft(i);
		else sortright(i);
	}
	for (i = 1; i <= num1; i++) printf("%c", left[i]);
	printf("%c", ch[0]);
	for (i = 1; i <= num2; i++) printf("%c", right[i]);
	return 0;
}
	void sortleft(int i)
	{
		num1++;
		left[num1] = ch[i];
	}
	void sortright(int i)
	{
		if (num2 == 0)
		{
			num2++;
			right[num2] = ch[i];
		}
		else
		{
			swapsort(ch[i], num2);
			num2++;
		}
	}
	void swapsort(char a,int length)
	{
		int i;
		for (i = 1; i <= length; i++)
		{
			if (a >= right[i]) continue;
				int j;
				for (j = length; j >= i; j--)
				{
					right[j + 1] = right[j];
				}
				right[i] = a;
				return;
		}
		right[length + 1] = a;
	}