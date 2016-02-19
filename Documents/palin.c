//To find the next palindrome of a given number
//By Syed Kaleemullah
#include<stdio.h>
#include<stdlib.h>
int main()
{
    char *num=malloc(128*sizeof(char));
    int len=0,pos,newpos,i,flag;
    scanf("%s",num);
    while(num[len]!='\0')
    {
        len++;
    }
    //Deciding the pivot element
    pos=(len%2==0)?(len/2)-1:len/2;
    pos=(pos==-1)?0:pos;
    //Deciding whether to change pivot
    for(i=pos;i>=0;i--)
    {
        if(num[i]>num[len-1-i])
        {
            flag=1;
            break;
        }
        else
        {
            flag=0;
            break;
        }
    }
    //Block to change pivot
    if(flag!=1)
    {
        num[pos]++;
        //If the pivot is 9
        if(num[pos]==58)
        {
            newpos=pos;
            while(newpos>=0)
            {
                if(num[newpos]==58 || num[newpos]=='9')
                {
                    num[newpos]='0';
                }
                else
                {
                    num[newpos]++;
                    break;
                }
                newpos--;
            }
        }
    }
    //creating the palindrome
    for(i=0;i<=pos;i++)
    {
        num[len-1-i]=num[i];
    }
    //Checking for all zeroes
    for(i=0;i<len;i++)
    {
        if(num[i]!='0')
        {
            flag=1;
            break;
        }
    }
    //If so converting it to palindrome
    if(flag!=1)
    {
        num[0]='1';
        num[len]='1';
        num[len+1]='\0';
    }
    printf("%s",num);
    return 0;
}
