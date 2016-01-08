#include<stdio.h>
#include<stdlib.h>
void main()
{
	int n,i,j,k;
	//Getting the number of rows
	printf("Enter the number of rows");
	scanf("%d",&n);
	//Creating matrix of size n
	int **a=calloc(n,sizeof(int *));
	for(i=0;i<n;i++)
	{
		 a[i]=calloc(n,sizeof(int));
	}
	//Declaring and printing the first element which is always 1
	a[0][0]=1;
	printf("%d\n",a[0][0]);
	//Printing the pattern
	for(i=1;i<n;i++)
	{
		//Steps to find the first element of row 
		a[i][0]=a[i-1][0]+(k=(i%2!=0?i:i-1));
		//Printing the first element of row
		printf("%d	",a[i][0]);
		//Calculating the second to last elements of row
		//Which is +2 to the previous element
		//Printing the elements	
		for(j=1;j<=i;j++)
		{
			a[i][j]=a[i][j-1]+2;
			printf("%d	",a[i][j]);
		}
		printf("\n");
	}
	
}
