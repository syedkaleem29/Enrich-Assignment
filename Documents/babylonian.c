#include<stdio.h>
float root(int num);
void main()
{
	int num;
	float result;
	scanf("%d",&num);
	result=root(num);
	printf("The Square Root of %d is %f\n",num,result);
}
float root(int num)
{
	float i,ave,div;
	float guess_num=num;
	for(i=0;i<10;i++)
	{	
		div=num/guess_num;
		ave=(div+guess_num)/2;
		guess_num=ave;
	}
	return ave;
}
