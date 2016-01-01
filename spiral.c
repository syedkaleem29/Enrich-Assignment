//Program to print elements of an matrix in a spiral manner
//By Syed Kaleemullah
#include<stdio.h>
#include<stdlib.h>
//A function to get the elements of the matrix
void getMatrix(int r,int c,int *a[c])
{
	int i,j;
	printf("Enter the elements of matrix\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
}
//A function to print the spiral once
void printSpiral(int m,int l,int r,int c,int *a[c])
{
	int i,j;
	//For printing elements in right direction
	i=m;
	for(j=l;j<c;j++)
	{
		printf("%d ",a[i][j]);
	}
	//For printing elements in down direction
	j=c-1;
	for(i=m+1;i<r;i++)
	{
		printf("%d ",a[i][j]);
	}
	//For printing elements in left direction
	if(m<r-1)
	{
		i=r-1;
		for(j=c-2;j>=m;j--)
		{
			printf("%d ",a[i][j]);
		}
	}
	//For printing elements in up direction
	if(l<c-1)
	{
		j=l;
		for(i=r-2;i>=m+1;i--)
		{
			printf("%d ",a[i][j]);
		}
	}
} 
void main()
{
	//Creating variables necessary
	int m=0,l=0,r,c,s,t,i,j,k;
	//Getting the number of rows and column
	printf("Enter row number ");
	scanf("%d",&r);
	printf("Enter column number ");
	scanf("%d",&c);
	//Operation to calculate the number of spirals
	s=r<c?r:c;
	t=s%2==0?(s/2):((s/2)+1);
	//Dynamic memory allocation of a 2D array
	int **a=calloc(r,sizeof(int *));
	for(i=0;i<r;i++)
	{
		 a[i]=calloc(c,sizeof(int));
	}
	//Calling the function to get Matrix
	getMatrix(r,c,a);
	//Acknowledgement for getting the Matrix
	printf("Got matrix\n");
	//Instruction to print spiral elements specific(t) number of times
	for(k=0;k<t;k++)
	{
		//Calling the function to print the spiral elements
		printSpiral(m,l,r,c,a);
		//Changing the arguments for the next spiral
		m++;
		l++;
		r--;
		c--;
	}
}
