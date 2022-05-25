#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
double a, b, c;
double delta,answer1,answer2;
int main()
{
	scanf("%lf%lf%lf", &a,&b,&c);
	delta = b*b - 4 * a*c;
	if (delta < 0)
	{
		printf("Error");
	}
	else if (delta == 0)
	{
		answer1 = (0 - b) / (2 * a);
		printf("%0.6f", answer1);
	}
	else
	{
		answer1 = (0 - b + sqrt(delta)) / (2 * a);
		answer2 = (0 - b - sqrt(delta)) / (2 * a);
		if (answer1 > answer2)
		{
			printf("%0.6f\n%0.6f", answer1, answer2);
		}
		else
		{
			printf("%0.6f\n%0.6f", answer1, answer2);
		}
	}
	return 0;
}