#include<stdio.h>
#include<stdlib.h>
void sort(char **,int);
void samelensort(char **,int *,int);
int main()
{
    int n,i;
    printf("No of elements\n");
    scanf("%d",&n);
    char **numarray=(char **)malloc(n*sizeof(char *));
    for(i=0;i<n;i++)
    {
        numarray[i]=(char *)malloc(sizeof(char));
    }
    for(i=0;i<n;i++)
    {
        scanf("%s",numarray[i]);
    }
    sort(numarray,n);
    for(i=0;i<n;i++)
    {
        printf("%s ",numarray[i]);
    }
    return 0;
}
void sort(char **numarray,int n)
{
    int *len=malloc(n*sizeof(int)),i,j,c,s,temp,pivot,flag=0,newpos;
    char *ctemp;
    for(i=0;i<n;i++)
    {
        c=0;
        while(numarray[i][c]!='\0')
        {
            c++;
        }
        len[i]=c;
    }
    for(i=0;i<n-1;i++)
    {
        pivot=len[i];
        flag=0;
        for(j=i+1;j<n;j++)
        {
            if(pivot>len[j])
            {
                pivot=len[j];
                newpos=j;
                flag=1;
            }
        }
        if(flag==1)
        {
            temp=len[i];
            len[i]=pivot;
            len[newpos]=temp;
            ctemp=numarray[i];
            numarray[i]=numarray[newpos];
            numarray[newpos]=ctemp;
        }
    }
    samelensort(numarray,len,n);
}
void samelensort(char **numarray,int *len,int n)
{
    int i,j,c=0,flag=0,newpos;
    char *ctemp;
    for(i=0;i<n-1;i++)
    {
       for(j=i+1;j<n;j++)
       {
            flag=0;
            newpos=0;
            if(len[i]==len[j])
            {
                c=0;
                while(numarray[i][c]!='\0')
                {
                    if(numarray[i][c]>numarray[j][c])
                    {
                        flag=1;
                        newpos=j;
                        break;
                    }
                    else if(numarray[i][c]<numarray[j][c])
                    {
                        flag=0;
                        break;
                    }
                    c++;
                }
                if(flag==1)
                {
                    ctemp=numarray[i];
                    numarray[i]=numarray[j];
                    numarray[j]=ctemp;
                }
            }
       }
    }
}
