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
    int len=strlen(str),slen,i,j,c=1,order=0,flag=0;
    char *res=malloc(sizeof(char));
    char *substr=malloc(sizeof(char));
    substr[0]=str[0];
    for(i=1;i<len;i++)
    {
        flag=0;
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
                substr=malloc(sizeof(char));
                c=0;
                substr[c++]=str[i];
                break;
            }
            else
            {
                flag=1;
            }
        }
        if(flag==1)
        {
            substr[c++]=str[i];
        
        }
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
