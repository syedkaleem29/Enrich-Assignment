#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student
{
	int sl,sub[5];
	float avg;
	char name[20];
};
struct student stud[9];
char* parse(char *);
float average(struct student );
int* highest(char *sub,int *,int *);
void main()
{
	int line=0,count=0,i,*no=malloc(sizeof(int)),marks;
	char buff[1024],*pbuff,*sub;
	FILE *fp=fopen("data.txt","r");
	FILE *fpo=fopen("data.txt","a");
	while(fgets(buff,sizeof(buff),fp))
	{
		if(++line==1)
		{
			continue;
		}
		pbuff=parse(buff);
		sscanf(pbuff,"%d %s %d %d %d %d %d",&stud[line-2].sl,stud[line-2].name,&stud[line-2].sub[0],&stud[line-2].sub[1],&stud[line-2].sub[2],&stud[line-2].sub[3],&stud[line-2].sub[4]);
	}
	fprintf(fpo,"Average\n");
	for(i=0;i<9;i++)
	{
		stud[i].avg=average(stud[i]);
		fprintf(fpo,"%f\n",stud[i].avg);
	}
	no=highest("eng",&count,&marks);
	fprintf(fpo,"The highest score of %d in English by:\n",marks);
	for(i=0;i<count;i++)
	{
		line=no[i];
		fprintf(fpo,"%s\n",stud[line].name);
	}
	no=highest("mat",&count,&marks);
	fprintf(fpo,"The highest score of %d in Mathematics by:\n",marks);
	for(i=0;i<count;i++)
	{
		line=no[i];
		fprintf(fpo,"%s\n",stud[line].name);
	}	
	no=highest("cse",&count,&marks);
	fprintf(fpo,"The highest score of %d in Computer Science by:\n",marks);
	for(i=0;i<count;i++)
	{
		line=no[i];
		fprintf(fpo,"%s\n",stud[line].name);
	}		
	no=highest("ele",&count,&marks);
	fprintf(fpo,"The highest score of %d in electronics by:\n",marks);
	for(i=0;i<count;i++)
	{
		line=no[i];
		fprintf(fpo,"%s\n",stud[line].name);
	}			
	no=highest("net",&count,&marks);
	fprintf(fpo,"The highest score of %d in Networking by:\n",marks);	
	for(i=0;i<count;i++)
	{
		line=no[i];
		fprintf(fpo,"%s\n",stud[line].name);
	}
}	
char* parse(char *buff)
{
	char *p=(char *)malloc(sizeof(char));
	int i=0;
	while(buff[i]!='\0')
	{
		if(buff[i]!=',')
		{
			p[i]=buff[i];
		}
		else
		{
			p[i]=' ';
		}
		i++;
	}
	return p;
}
float average( struct student stud)
{
	float avg=(stud.sub[0]+stud.sub[1]+stud.sub[2]+stud.sub[3]+stud.sub[4])/(float)5;
	return avg;
}
int* highest(char *sub,int *c,int *marks)
{
	int d=1;
	FILE *fpo=fopen("data.txt","a");
	int subId,order=0,i;
	int *h=malloc(sizeof(int));
	if(sub=="eng")
	{
		subId=0;
	}	
	else if(sub=="mat")
	{
		subId=1;
	}
	else if(sub=="cse")
	{
		subId=2;
	}
	else if(sub=="ele")
	{
		subId=3;
	}
	else
	{
		subId=4;
	}
	for(i=0;i<9;i++)
	{
		if(order<stud[i].sub[subId])
		{
			order=stud[i].sub[subId];
			d=1;
			h[0]=i;
		}
		else if(order==stud[i].sub[subId])
		{
			h[d++]=i;
		}
	}
	*c=d;
	*marks=order;
	return h;
}
