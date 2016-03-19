//
//  main.c
//  code1
//
//  Created by R.M.D. Engineering College  on 19/03/16.
//  Copyright © 2016 R.M.D. Engineering College . All rights reserved.
//

#include <stdio.h>
struct object
{
    int no;
    int cost;
    int kg;
};
int main(int argc, const char * argv[]) {
    // insert code here...
    int i,j,jpos=0,n,pivot,otemp,temp,flag=0,weight;
    int num,kgs,total_w,value,total_v;
    scanf("%d",&weight);
    scanf("%d",&n);
    struct object o[n];
    int order[n];
    float costkg[n];
    for(i=0;i<n;i++)
    {
        printf("Enter the details\n");
        scanf("%d",&o[i].no);
        scanf("%d",&o[i].cost);
        scanf("%d",&o[i].kg);
        costkg[i]=o[i].cost/(float)o[i].kg;
        order[i]=i;
    }
    for(i=0;i<n;i++)
    {
        pivot=costkg[i];
        flag=0;
        jpos=0;
        for(j=i+1;j<n;j++)
        {
            if(pivot<costkg[j])
            {
                pivot=costkg[j];
                flag=1;
                jpos=j;
            }
        }
        if(flag==1)
        {
            temp=costkg[i];
            costkg[i]=costkg[jpos];
            costkg[jpos]=temp;
            otemp=order[i];
            order[i]=order[jpos];
            order[jpos]=otemp;
        }
    }
    i=0;
    for(i=0;i<n;i++)
    {
        num=o[order[i]].no;
        kgs=o[order[i]].kg;
        total_w=(num*kgs);
        while(total_w>weight)
        {
            num=o[order[i]].no--;
            total_w=num*kgs;
        }
        weight=weight-total_w;
        value=num*o[order[i]].cost;
        total_v+=value;
        printf("%d no of %d kg of %d value is used\n",num,kgs,o[order[i]].cost);
        if(weight<=0)
        {
            break;
        }
    }
    printf("Total Value:%d\n",total_v);
    return 0;
}
