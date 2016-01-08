#include<stdio.h>
#include<stdlib.h>
void main()
{
	//Declaring variables
	int n,i,j,k;
	//getting the number of rows
	printf("Enter the number of rows");
	scanf("%d",&n);
	//Creating the matrix
	int **a=calloc(n,sizeof(int *));
	for(i=0;i<n;i++)
	{
		 a[i]=calloc(n,sizeof(int));
	}
	//Declaring and printing the first element equal to one
	a[0][0]=1;
	printf("%d\n",a[0][0]);
	//Procedure to print pattern
	for(i=1;i<n;i++)
	{
		a[i][0]=1;
		a[i][i]=1;
		//Printing the first element of row which is always 1
		printf("%d	",a[i][0]);	
		//Steps to calculate the between the first and last elements
		//Printing the elements between the first and last elements  		
		for(j=1;j<i;j++)
		{
			a[i][j]=a[i-1][j-1]+a[i-1][j];
			printf("%d	",a[i][j]);
		}
		//Printing the last element of row which is always 1
		printf("%d	",a[i][i]);
		printf("\n");
	}
	
}
