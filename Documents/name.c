//
//  main.c
//  syed
//
//  Created by R.M.D. Engineering College  on 05/03/16.
//  Copyright © 2016 R.M.D. Engineering College . All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
void unique(char **, int);
void freq(char **,char**,int,int);
int same(char *,char *);
int main(int argc, const char * argv[]) {
    // insert code here...
    int n,i,j,c=0;
    scanf("%d",&n);
    int *roll=malloc(n*sizeof(int));
    char **name=malloc(n*sizeof(char*));
    char **new_name=malloc(n*sizeof(char*));
    char **uniq_name=malloc(n*sizeof(char*));
    for(i=0;i<n;i++)
    {
        name[i]=malloc(sizeof(char));
        new_name[i]=malloc(sizeof(char));
        uniq_name[i]=malloc(sizeof(char));
    }
    for(i=0;i<n;i++)
    {
        scanf("%d",&roll[i]);
        scanf(" %[^\n]s",name[i]);
    }
    for(i=0;i<n;i++)
    {
        c=0;
        j=0;
        while(name[i][j]!='\0')
        {
            new_name[i][c++]=name[i][j];
            if(name[i][j]=='.')
            {
                c=0;
            }
            if(name[i][j]==' ')
            {
                break;
            }
            j++;
        }
    }
    unique(new_name,n);
    return 0;
}
void unique(char **new_name,int n)
{
    int i=0,j=0,flag=0;
    int c=0;
    char **uniq=malloc(n*sizeof(char *));
    for(i=0;i<n;i++)
    {
        uniq[i]=malloc(sizeof(char));
    }
    uniq[c++]=new_name[0];
    for(i=1;i<n;i++)
    {
        flag=0;
        for(j=0;j<i;j++)
        {
            if(!same(new_name[i],new_name[j]))
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
            uniq[c++]=new_name[i];
        }
    }
    freq(uniq,new_name,c,n);
}
void freq(char **uniq,char **name,int c,int n)
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
            if(same(uniq[i],name[j]))
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