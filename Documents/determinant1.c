//Program to calculate determinant of matrix of any order
//By Syed Kaleemullah
#include<stdio.h>
void main()
{	
	int n,i,j,k,s,c=0; 
	float mul,dnum,ans=1;
	//getting the order
	printf("Enter the size of the matrix");
	scanf("%d",&n);
	//cresting matrix of the order
	float mat[n][n];
	//getting the matrix
	for(i=0;i<n;i++)
	{
			for(j=0;j<n;j++)
			{
				scanf("%f",&mat[i][j]);
			}
	}
	//Calculation of determinant
	for(i=0;i<n-1;i++)
	{
		//if the diagonal elements is zero
		if(mat[i][i]==0)
		{
			//To find a position of non zero element below the diagonal element
			for(j=i+1;j<n;j++)
			{
				//If found swap counter is incremented 
				if(mat[j][i]!=0)
				{
					c++;
					break;
				}
				//Else the value of determinant is 0
				else
				{
					printf("The value of determinant is 0");
					return;
				}
			}
			//The new row and original row are swaped 
			for(k=0;k<n;k++)
			{
				s=mat[i][k];
				mat[i][k]=mat[j][k];
				mat[j][k]=s;
			}						
		}
		//Code for gauss elimination
		for(j=i+1;j<n;j++)
		{	
			dnum=mat[j][i];
			mul=dnum/mat[i][i];
			for(k=0;k<n;k++)
			{	
				mat[j][k]=mat[j][k]-(mul*mat[i][k]);		
			}
		}
		//ans is obtained by multipliying diagonal element
		ans=ans*mat[i][i];	
	}
	//determinant of matrix is obtained by multiplying the final element with ans variable 
	ans=ans*mat[n-1][n-1];
	//If swap counter is not zero then it is used to get answer with correct sign  
	if(c!=0)
	{
		ans=ans*-1*c;
	}
	//The determinant of the matrix is printed
	printf("The value of determinant is %f\n",ans);
}
