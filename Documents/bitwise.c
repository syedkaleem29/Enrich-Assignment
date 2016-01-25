#include<stdio.h>
void given(unsigned char);
void bitset(unsigned char ,int);
void bitunset(unsigned char ,int);
void toggle(unsigned char ,int);
void toggleExcept(unsigned char *,int);
void right(unsigned char );
void left(unsigned char );
void swap(unsigned char );
void print(unsigned char );
void main()
{
	unsigned char num=11;
	int index=2;
	given(num);
	bitset(num,index);
	bitunset(num,index);
	toggle(num,index);
	toggleExcept(&num,index);
	num=11;
	right(num);
	left(num);
	swap(num);
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
void given(unsigned char num)
{
	printf("Given Number:");
	print(num);
	printf("\nDecimal Value:%d\n\n",num);	
}
void bitset(unsigned char num,int index)
{
	int flag=1;
	num=num|(flag<<index);
	printf("Bit 2 set to 1:");
	print(num);
	printf("\nDecimal Value: %d\n\n",num);
}
void bitunset(unsigned char num,int index)
{
	int flag=1;
	num=num&~(flag<<index);
	printf("Bit 2 set to 0: ");
	print(num);
	printf("\nDecimal Value: %d\n\n",num);
}
void toggle(unsigned char num,int index)
{
	int flag=1;
	num=~num^~(flag<<index);
	printf("Toggle Bit 2: ");
	print(num);		
	printf("\nDecimal Value %d\n\n",num);
}
void toggleExcept(unsigned char *num,int index)
{
	int flag=1;	
	*num=~*num|(flag<<index);
	printf("Toggle Except bit 2: ");
	print(*num);
	printf("\nDecimal Value %d\n\n",*num);
}
void right(unsigned char num)
{	
	num=(num>>1)|(num<<7);
	printf("Rotate Right ");
	print(num);	
	printf("\nDecimal Value:%d\n\n",num);
}
void left(unsigned char num)
{	
	num=(num<<1)|(num>>7);
	printf("Rotate left ");
	print(num);	
	printf("\nDecimal Value:%d\n\n",num);
}
void swap(unsigned char num)
{
	num=(num<<4)|(num>>4);
	printf("Swap Nibble: ");
	print(num);
	printf("\nDecimal Value:%d\n\n",num);
}
