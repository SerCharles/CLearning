#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
unsigned int n;
unsigned int forward=0x00,backward=0x00,ans=0x00;
int main()
{
	scanf("%d",&n);
backward = n & 0xFFFF;
forward = n >> 16;
ans = backward << 16;
ans = ans+ forward;
printf("%d", ans);
return 0;
}