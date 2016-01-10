//Program to generate Msgic Square using the Siamese Method
//By Syed Kaleemullah
#include<stdio.h>
#include<stdlib.h>
void main()
{
	//Declaring Variables
	//Inialising number to 1 
	int n,a,b,num=1;
	//Getting the order of the matrix
	printf("Enter the order");
	scanf("%d",&n);
	//Dynamically allocating the memory for the matrix
	int **mat=calloc(n,sizeof(int *));
	for(a=0;a<n;a++)
	{
		mat[a]=calloc(n,sizeof(int));
	}
	//Calculating the position of the first element which is always the same
	a=0;
	b=n/2;
	mat[a][b]=1;
	//Placing other elements of the matrix using the siamese method
	for(num=2;num<=n*n;num++)
	{
		//Moving one place top-right
		a=a-1;
		b=b+1;
		//If mat[0][n-1] is moved then changing would result in mat[-1][n]
		//In such case we have to move one position down to mat[1][n-1]		
		if(a==-1 && b==n)
		{
			a=1;
			b=n-1;
		}
		//If position moves above the top row then it brought down to the last row 		
		if(a==-1)
		{
			a=n-1;
		}
		//If position moves to the right of the top column then it is moved to the first column
		if(b==n)
		{
			b=0;
		}
		//If no element is present in mat[a][b] place it there
		//else move it to two position down and one to the left
		if(mat[a][b]==0)
		{
			mat[a][b]=num;
		}
		else
		{
			a=a+2;
			b=b-1;
			mat[a][b]=num;
		}	
	}
	printf("The magic square is\n");
	for(a=0;a<n;a++)
	{
		for(b=0;b<n;b++)
		{
			printf("%d	",mat[a][b]);
		}
		printf("\n");
	}
}
