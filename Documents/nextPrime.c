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
<<<<<<< HEAD
	int i,j,flag;
	if(num==1|| num==0)
=======
	int j=3;
	if(num<2)
>>>>>>> origin/master
	{
		return 2;
	}
	num=(num%2)==0?num+1:num+2;
	for(i=num;;i=i+2)
	{
		flag=1;
		for(j=2;j<=sqrt(num);j++)
		{
<<<<<<< HEAD
			if(i%j==0)
			{
				flag=0;
			}
		}
		if(flag==1)
		{
			return i;		
		}
=======
			num=num+2;
			j=3;
			continue;
		}
		j=j+2;
>>>>>>> origin/master
	}
	return num;
}
