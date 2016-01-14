#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
void main()
{
	system("clear");
	char string[]="Happy Pongal";
	int i;
	for(i=0;string[i]!='\0';i++)
	{
		printf("%c",string[i]);
		fflush(stdout);
		sleep(1);
	}
	system("clear");
}
