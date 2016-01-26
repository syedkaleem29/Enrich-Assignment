#include<stdio.h>
unsigned char given(unsigned char);
unsigned char bitset(unsigned char ,int);
unsigned char bitunset(unsigned char ,int);
unsigned char toggle(unsigned char ,int);
unsigned char toggleExcept(unsigned char *,int);
unsigned char right(unsigned char );
unsigned char left(unsigned char );
unsigned char swap(unsigned char );
void print(unsigned char );
void printOutput(unsigned char );
void main()
{
	unsigned char num=11,numout;
	int index=2;
	printf("Given Number ");
	numout=given(num);
	printOutput(numout);
	printf("Bit 2 set to 1: ");
	numout=bitset(num,index);
	printOutput(numout);
	printf("Bit 2 set to 0: ");
	numout=bitunset(num,index);
	printOutput(numout);	
	printf("Toggle Bit 2: ");
	numout=toggle(num,index);
	printOutput(numout);
	printf("Toggle Except bit 2: ");
	numout=toggleExcept(&num,index);
	printOutput(numout);	
	num=11;
	printf("Rotate Right ");
	numout=right(num);
	printOutput(numout);
	printf("Rotate left ");
	numout=left(num);
	printOutput(numout);
	printf("Swap Nibble: ");
	numout=swap(num);
	printOutput(numout);
}
void printOutput(unsigned char numout)
{
	print(numout);
	printf("\nDecimal Value: %d\n\n",numout);
}
void print(unsigned char num)
{
	int number=(int)num;
	int i,n=128;
	for(i=0;i<8;i++)
	{
		if(n>number)
		{
			printf("0");
		}
		else
		{
			printf("1");
			number=number-n;
		}
		n=n/2;
	}
}
unsigned char given(unsigned char num)
{
	return num;
}
unsigned char bitset(unsigned char num,int index)
{
	int flag=1;
	num=num|(flag<<index);
	return num;
}
unsigned char bitunset(unsigned char num,int index)
{
	int flag=1;
	num=num&~(flag<<index);
	return num;
}
unsigned char toggle(unsigned char num,int index)
{
	int flag=1;
	num=num^(flag<<index);
	return num;
}
unsigned char toggleExcept(unsigned char *num,int index)
{
	int flag=1;	
	*num=~*num|(flag<<index);
	return *num;	
}
unsigned char right(unsigned char num)
{	
	if(num%2==0)
	{
		num=num/2;
	}
	else
	{
		num=128+(num/2);
	}
	return num;
}
unsigned char left(unsigned char num)
{	
	if(num>=128)
	{
		num=1+(num*2);
	}
	else
	{
		num=num*2;
	}
	return num;	
}
unsigned char swap(unsigned char num)
{
	num=(num<<4)|(num>>4);
	return num;	
}
