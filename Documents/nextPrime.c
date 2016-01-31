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
	int j=3;
	if(num<2)
	{
		return 2;
	}
	num=(num%2)==0?num+1:num+2;
	while(j<=sqrt(num))
	{
		if(num%j==0)
		{
			num=num+2;
			j=3;
			continue;
		}
		j=j+2;
	}
	return num;
}