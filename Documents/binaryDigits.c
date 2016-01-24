#include<stdio.h>
int binaryDigits(int);
void main()
{
	int num;
	printf("Enter the number:");
	scanf("%d",&num);
	printf("The number of binary digits is %d\n",binaryDigits(num));	
}
int binaryDigits(int num)
{
	int count=0;
	while(num!=0)
	{
		num=num/2;
		count++;
	}
	return count;
}
