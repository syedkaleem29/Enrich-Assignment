//Program to calculate determinant of matrix of any order
//By Syed Kaleemullah
#include<stdio.h>
void main()
{	
	int n,i,j,k,s,c=0; 
	float mul,dnum,ans=1;
	printf("Enter the size of the matrix");
	scanf("%d",&n);
	float mat[n][n];
	for(i=0;i<n;i++)
	{
			for(j=0;j<n;j++)
			{
				scanf("%f",&mat[i][j]);
			}
	}
	for(i=0;i<n-1;i++)
	{
		if(mat[i][i]==0)
		{
			for(j=i+1;j<n;j++)
			{
				if(mat[j][i]>0)
				{
					c++;
					break;
				}
				else
				{
					printf("The value of determinant is 0");
					return;
				}
			}
			for(k=0;k<n;k++)
			{
				s=mat[i][k];
				mat[i][k]=mat[j][k];
				mat[j][k]=s;
			}						
		}
		for(j=i+1;j<n;j++)
		{	
			dnum=mat[j][i];
			mul=dnum/mat[i][i];
			for(k=0;k<n;k++)
			{	
				mat[j][k]=mat[j][k]-(mul*mat[i][k]);		
			}
		}
		ans=ans*mat[i][i];	
	}
	ans=ans*mat[n-1][n-1];
	if(c!=0)
	{
		ans=ans*-1*c;
	}
	printf("The value of determinant is %f\n",ans);
}
