#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
double a, b, c;
double p,s,answer;
void sort()
{
	if (a < b)
	{
		double temp;
		temp = a;
		a= b;
		b = temp;
	}
	if (a < c)
	{
		double temp;
		temp = a;
		a= c;
		c = temp;
	}
}

int main()
{
	scanf("%lf %lf %lf", &a, &b, &c);
	sort();
	if (b + c <= a)
	{
		printf("NO");
	}
	else
	{
		p = (a + b + c) / 2;
		s = sqrt(p*(p - a)*(p - b)*(p - c));
		answer = (s * 2) / a;
		printf("%0.6f", answer);
	}
	return 0;
}