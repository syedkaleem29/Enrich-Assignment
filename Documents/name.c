//
//  Created by R.M.D. Engineering College  on 05/03/16.
//  Copyright © 2016 R.M.D. Engineering College . All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
struct student
{
    char *name;
    char *first_name;
    int roll;
};
void unique(struct student *, int);
void freq(char **,struct student *,int,int);
int same(char *,char *);
int main(int argc, const char * argv[]) {
    // insert code here...
    int n,i,j,c=0;
    scanf("%d",&n);
    struct student std[n];
    for(i=0;i<n;i++)
    {
        std[i].name=malloc(sizeof(char));
        std[i].first_name=malloc(sizeof(char));
    }
    for(i=0;i<n;i++)
    {
        scanf("%d",&std[i].roll);
        scanf(" %[^\n]s",std[i].name);
    }
    for(i=0;i<n;i++)
    {
        c=0;
        j=0;
        while(std[i].name[j]!='\0')
        {
            std[i].first_name[c++]=std[i].name[j];
            if(std[i].name[j]=='.')
            {
                c=0;
            }
            if(std[i].name[j]==' ')
            {
                break;
            }
            j++;
        }
    }
    unique(std,n);
    return 0;
}
void unique(struct student *std,int n)
{
    int i=0,j=0,flag=0;
    int c=0;
    char **uniq=malloc(n*sizeof(char *));
    for(i=0;i<n;i++)
    {
        uniq[i]=malloc(sizeof(char));
    }
    uniq[c++]=std[0].first_name;
    for(i=1;i<n;i++)
    {
        flag=0;
        for(j=0;j<i;j++)
        {
            if(!same(std[i].first_name,std[j].first_name))
            {
                flag=1;
            }
            else
            {
                flag=0;
                break;
            }
        }
        if(flag==1)
        {
            uniq[c++]=std[i].first_name;
        }
    }
    freq(uniq,std,c,n);
}
void freq(char **uniq,struct student *std,int c,int n)
{
    int i,j,k,co=0;
    int *f=calloc(n,sizeof(int));
    int roll[n][n];
    for(i=0;i<c;i++)
    {
        co=0;
        printf("%s,",uniq[i]);
        for(j=0;j<n;j++)
        {
            if(same(uniq[i],std[j].first_name))
            {
                f[i]++;
                roll[i][co++]=j+1;
            }
        }
        printf("%d,",f[i]);
        printf("[");
        for(k=0;k<co;k++)
        {
            printf("%d",roll[i][k]);
            if(k==co-1)
            {
                printf("]\n");
            }
            else
            {
                printf(",");
            }
        }
    }
}
int same(char *name1,char *name2)
{
    int ans=0;
    int i=0,j=0;
    while(name1[i]!='\0' && name2[j]!='\0')
    {
        if(name1[i]==name2[j])
        {
            ans=1;
        }
        else
        {
            ans=0;
            break;
        }
        i++;
        j++;
    }
    if(ans==1)
    {
        if(i==j)
        {
            ans=1;
        }
        else
        {
            ans=0;
        }
    }
    return ans;
}
