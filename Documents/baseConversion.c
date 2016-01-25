#include<stdio.h>
void baseConversion(int,int);
void print(int,char *);
void main()
{
	int num,base;
	printf("Enter the number:");
	scanf("%d",&num);
	printf("Enter the base:");
	scanf("%d",&base);
	if(base>=2 || base<=36 )
	{
		baseConversion(num,base);
	}
}
void baseConversion(int num,int base)
{
	int quo=1,rem,i=0;
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
	print(i,conv);
}
void print(int n,char conv[])
{
	int i;
	for(i=n-1;i>=0;i--)
	{
		printf("%c",conv[i]);
	}
	printf("\n");
}
