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
		multi[num][i] = temp% 10;                         //ģ��˷����㣺ÿһλ�ȳ��ϴ�������Ȼ���λ
		multi[num][i + 1] = multi[num][i + 1] + temp / 10;  //��λ����
	}
	if (multi[num][len + 1] == 0 && multi[num][len + 2] == 0)
	{
		length[num] = len;   //�������⣬���Ҫ��50������ÿһλ��������ܴﵽ���٣�
		                     //�������տ��ܲ���λ�� ���ܽ�һλ�����ܽ���λ
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
	{                                       //�ӷ����������������ĸ���λ���࣬Ȼ������λ�����λ���
		                                    //Ȼ����н�λ������                                  
		temp = answer[i] + multi[num][i];   //����⻹����ȷ���߾���+�;��ȵ���������Ȼ�߾�����λ����
		answer[i] = temp % 10;
		answer[i + 1] = answer[i + 1] + temp / 10;
	}
}
int main()
{
	scanf("%d", &n);//����n
	int i;
	multi[1][1] = 1;
	length[1] = 1;  //��ʼ��
	for (i = 2; i <= n; i++)
	{
		multiply(i,length[i-1]);    //�������˲��洢
	}
	for (i = 1; i <= n; i++)
	{
		plus(i);   //�������Ӳ��洢
	}
	if (answer[length[n] + 1] != 0) anslen = length[n] + 1;
	else anslen = length[n];
	for (i = anslen; i >= 1; i--)
	{
		printf("%d", answer[i]);   //���������ԭ���Ǽӷ��˷����㶼�ǵ�λ����λ���㣬
		                           //  ������Ľ���Ǹ�λ����λ
	}
	while (1);
	return 0;
}*/