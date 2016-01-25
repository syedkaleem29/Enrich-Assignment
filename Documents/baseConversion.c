#include<stdio.h>
void baseConversion(int,int);
void main()
{
	int num,base;
	printf("Enter the number:");
	scanf("%d",&num);
	printf("Enter the base:");
	scanf("%d",&base);
	baseConversion(num,base);
}
void baseConversion(int num,int base)
{
	int quo=1,rem,i=0,j;
	char conv[128];
	while(quo!=0)
	{
		quo=num/base;
		rem=num%base;
		if(rem<=9)
		{
			conv[i++]=rem+48;//used to convert n to 'n'		
		}
		else
		{
			conv[i++]=rem+55;//used to convert 10,11,12... to 'A','B','C'...
		}
		num=quo;
	}
	for(j=i-1;j>=0;j--)
	{
		printf("%c",conv[j]);
	}
	printf("\n");
}
