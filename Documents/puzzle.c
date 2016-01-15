//Square Puzzle
//By Syed Kaleemullah
#include<stdio.h>
#include<stdlib.h>
//Function to display the matrix
void printArray(int array[][4])
{
	int i,j;
	for(i=0;i<4;i++)
	{
		printf("------------------------------\n");
		for(j=0;j<4;j++)
		{
			if(array[i][j]!=0)
			{
				printf("|%d|	",array[i][j]);
			}
			else
			{
				printf("| |	");
			}
		}
		printf("\n");
	}
	printf("------------------------------\n");
	printf("U for Up,D for Down,L for Left,R for right,Q to quit\n");
}
//Function to find position of the empty
void findEmpty(int *row,int *col,int array[][4])
{
	int i,j;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			if(array[i][j]==0)
			{
				*row=i;
				*col=j;
			}
		}
	}
}
//Function to swap depending on the character entered
void swap(int row,int col,char swapdir, int array[][4])
{
	int temp;
	if(swapdir=='U' && row!=0)
	{
		temp=array[row][col];
		array[row][col]=array[row-1][col];
		array[row-1][col]=temp;
	}
	if(swapdir=='R' && col!=3)
	{
		temp=array[row][col];
		array[row][col]=array[row][col+1];
		array[row][col+1]=temp;
	}
	if(swapdir=='L'&& col!=0)
	{
		temp=array[row][col];
		array[row][col]=array[row][col-1];
		array[row][col-1]=temp;
	}
	if(swapdir=='D' && row!=3)
	{
		temp=array[row][col];
		array[row][col]=array[row+1][col];
		array[row+1][col]=temp;
	}
}
void main()
{
	int row,col;
	char swapdir;
	int array[4][4]={1,2,3,4,5,6,7,8,9,0,10,11,12,13,14,15};
	while(1)
	{	
		system("clear");
		printArray(array);
		printf("Enter the Character(Caps Only)\n");
		scanf("%c",&swapdir);
		if(swapdir=='Q')
		{
			system("clear");
			return;
		}
		findEmpty(&row,&col,array);
		swap(row,col,swapdir,array);
	}
}
