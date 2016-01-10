//Combination of number in an array without repition 
//By Syed Kaleemullah
#include<stdio.h>
#include<math.h>
//For an array of size n, There are 2^n-1 possible combination of numbers.
//and binary value of numbers from 1 to 2^n-1 numbers can be used to represent the possible combinations
//Example consider an array [1,2,3]
//There are 2^3-1=7 possible combinations
//The reverse binary number from 1 to 7 can represent all possible combination
//    Number 	Reverse Binary Number Combination
//	1		100		1
//	2		010		2
//	3		110		2 1
//	4		001		3
//	5		101		1 3
//	6		011		2 3
//	7 		111		1 2 3
//This function is used to print combination
void printComb(int size,int *array,int *binaryarr)
{
	int i;
	for(i=0;i<size;i++)
	{
		if(binaryarr[i]==1)
		{
			printf("%d ",array[i]);
		}
	}
}
//This function is used to find reverse of binary of a number
void binaryOfNum(int num,int size,int *array)
{
	int diff,i;
	int power=size-1,power2;
	int binaryarr[size];
	while(power>=0)
	{
		power2=pow(2,power);
		diff=num-power2;
		if(diff>=0)
		{
			binaryarr[power]=1;
		}
		else
		{
			binaryarr[power]=0;
			diff=num;
		}
		num=diff;
		power--;
	}
	printComb(size,array,binaryarr);
	printf("\n");
}
//This function is used to determine number of combination
void numOfComb(int *array,int size)
{	
	int max,num=1;
	max=pow(2,size)-1;
	while(num<=max)
	{
		binaryOfNum(num,size,array);
		num++;
	}
}
void main()
{
	int size,i;
	scanf("%d",&size);
	int array[size];
	for(i=0;i<size;i++)
	{
		scanf("%d",&array[i]);
	}
	printf("The possible combination are:\n");
	numOfComb(array,size);
}
