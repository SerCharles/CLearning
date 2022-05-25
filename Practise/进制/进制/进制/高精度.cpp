/*#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
int n,anslen;
int multi[60][110] = { 0 }, length[60] = { 0 }, answer[110] = { 0 };
void multiply(int num,int len)
{
	int i,temp;
	for (i = 1; i<= len+1; i++)
	{
		temp = multi[num - 1][i] * num+ multi[num][i];     
		multi[num][i] = temp% 10;                         //模拟乘法运算：每一位先乘上待乘数，然后进位
		multi[num][i + 1] = multi[num][i + 1] + temp / 10;  //进位操作
	}
	if (multi[num][len + 1] == 0 && multi[num][len + 2] == 0)
	{
		length[num] = len;   //根据题意，最多要乘50，这样每一位的数最多能达到几百，
		                     //所以最终可能不进位， 可能进一位，可能进两位
	}
	else if (multi[num][len + 1] != 0 && multi[num][len + 2] == 0)
	{
		length[num] = len + 1;
	}
	else if (multi[num][len + 2] != 0)
	{
		length[num] = len + 2;
	}
}
void plus(int num)
{
	int i,temp;
	for (i = 1; i <= length[num]; i++)
	{                                       //加法则是这样：先找哪个数位数多，然后从最低位到最高位相加
		                                    //然后进行进位操作。                                  
		temp = answer[i] + multi[num][i];   //这道题还算明确：高精度+低精度的数，很显然高精度数位数多
		answer[i] = temp % 10;
		answer[i + 1] = answer[i + 1] + temp / 10;
	}
}
int main()
{
	scanf("%d", &n);//读入n
	int i;
	multi[1][1] = 1;
	length[1] = 1;  //初始化
	for (i = 2; i <= n; i++)
	{
		multiply(i,length[i-1]);    //进行连乘并存储
	}
	for (i = 1; i <= n; i++)
	{
		plus(i);   //进行连加并存储
	}
	if (answer[length[n] + 1] != 0) anslen = length[n] + 1;
	else anslen = length[n];
	for (i = anslen; i >= 1; i--)
	{
		printf("%d", answer[i]);   //倒序输出：原因是加法乘法运算都是低位到高位运算，
		                           //  而输出的结果是高位到低位
	}
	while (1);
	return 0;
}*/