#include<stdio.h>
void main()
{
	//declaring variables and creating the first element num equal to 1
	int n,i,j,num=1;
	//Getting the number of rows to be printed
	printf("Enter the number of rows");
	scanf("%d",&n);
	//Printing the pattern
	for(i=0;i<n;i++)
	{
		for(j=0;j<i;j++)
		{
			printf("%d	",num++);
		}
	printf("\n");
	}
}
