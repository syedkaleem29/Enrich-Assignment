#include<stdio.h>
#include<math.h>
int nextPrime(int num);
void main()
{
	int num,prime;
	scanf("%d",&num);
	prime=nextPrime(num);
	printf("The Next Prime Number is %d",prime);
}
int nextPrime(int num)
{
	int i,flag;
	if(num==1|| num==0)
	{
		return 2;
	}
	num=(num%2)==0?num+1:num+2;
	for(i=2;i<=sqrt(num);i++)
	{	
		flag=1;
		if(i%j==0)
		{
			flag=0;
			num=num+2;
		}
		if(flag==1)
		{
			return num;		
		}
	}
}
