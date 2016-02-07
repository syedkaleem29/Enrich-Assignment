#include<stdio.h>
#include<stdlib.h>
char* substring(char*);
int strlen(char*);
int main()
{
    char *str=malloc(sizeof(char));
    char *res;
    scanf("%s",str);
    res=substring(str);
    printf("%s\n",res);
    printf("%d\n",strlen(res));
    return 0;
}
char* substring(char *str)
{
	int c=0,s=0,i=s,j,len=strlen(str),order=0,slen;
    char *res=malloc(sizeof(char));
    char *substr=malloc(sizeof(char));
    while(i<len)
    {
		for(j=0;j<i;j++)
		{
			if(str[i]==substr[j])
			{
				slen=strlen(substr);
				if(order<slen)
				{
					res=substr;
					order=slen;
				}
				i=s+1;
				s++;
				c=0;
				substr=malloc(sizeof(char));
				break;
			}
		}
		substr[c++]=str[i];
		printf("%s\n",substr);
		i++;
    }
	slen=strlen(substr);
	if(order<slen)
	{
		res=substr;
	}
    return res;
}
int strlen(char *str)
{
    int i=0;
    while(str[i]!=0)
    {
        i++;
    }
    return i;
}
