//Program to calculate determinant of matrix of any order
//By Syed Kaleemullah
#include<stdio.h>
void main()
{	
	//Variables for order and iteration
	int n,i,j,k; 
	//Variables for calculation
	float mul,ans,dnum;
	printf("Enter the size of the matrix");
	scanf("%d",&n);
	float mat[n][n];
	//Getting the value for the matrix
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%f",&mat[i][j]);
		}
	}
	ans=mat[0][0];
	//Calculation of the determinant
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{	
			dnum=mat[j][i];
			mul=dnum/mat[i][i];
			for(k=0;k<n;k++)
			{
				
				mat[j][k]=mat[j][k]-(mul*mat[i][k]);
				
			}
		}
		ans*=mat[i+1][i+1];
	}
	//Answer
	printf("The value of determinant is %f\n",ans);
}
