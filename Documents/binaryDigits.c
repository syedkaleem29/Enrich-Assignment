#include<stdio.h>
#include<math.h>
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
	int pow2=0,p=0;
	while(pow2<=num)
	{
		p++;
		pow2=pow(2,p);
	}
	return p;
}
