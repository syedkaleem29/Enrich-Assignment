#include<stdio.h>
#include<stdlib.h>
void sort(char **,int);
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
    int *sum=malloc(n*sizeof(int)),i,j,c,s,temp,pivot,flag=0,newpos;
    char *ctemp;
    for(i=0;i<n;i++)
    {
        c=0;
        s=0;
        while(numarray[i][c]!='\0')
        {
            s+=numarray[i][c];
            c++;
        }
        sum[i]=s;
    }
    for(i=0;i<n-1;i++)
    {
        pivot=sum[i];
        flag=0;
        for(j=i+1;j<n;j++)
        {
            if(pivot>sum[j])
            {
                pivot=sum[j];
                newpos=j;
                flag=1;
            }
        }
        if(flag==1)
        {
            temp=sum[i];
            sum[i]=pivot;
            sum[newpos]=temp;
            ctemp=numarray[i];
            numarray[i]=numarray[newpos];
            numarray[newpos]=ctemp;
        }
    }
}
