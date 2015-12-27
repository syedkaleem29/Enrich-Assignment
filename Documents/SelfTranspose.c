//Self Transpose of a square matrix 
//By Syed Kaleemullah
#include<stdio.h>
#include<stdlib.h>
void getMatrix(int r,int c,int *a[c])
{
	int i,j;
	printf("Enter the elements\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	
}
void printMatrix(int r,int c,int *a[c])
{
	int i,j;
	printf("The transpose of matrix is\n");
	for(i=0;i<c;i++)
	{
		for(j=0;j<r;j++)
		{
			printf("%d 	",a[i][j]);
		}
		printf("\n");
	}
}
void main()
{
	//Declaring variables for iteration and order
	int i,j,r,c,t,max;
	//Getting the order
	printf("Enter the order\n");
	scanf("%d",&r);
	scanf("%d",&c);
	max=r>c?r:c;
	//Dynamic memory allocation of a 2D array
	int **a=calloc(max,sizeof(int *));
	for(i=0;i<max;i++)
	{
		 a[i]=calloc(max,sizeof(int));
	}
	//Getting the elements
	getMatrix(r,c,a);
	//Performing the operations for transpose
	for(i=0;i<max-1;i++)
	{
		for(j=i+1;j<max;j++)
		{
			t=a[i][j];
			a[i][j]=a[j][i];
			a[j][i]=t;
		}
	}
	//Displaying the transposed matrix 
	printMatrix(r,c,a);
}

