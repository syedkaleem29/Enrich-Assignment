#include<stdio.h>
#include<stdlib.h>
void onedigit(char);
void twodigit(char,char);
void threedigit(char,char,char);
void teen(char);
void tens(char);
int main()
{
    char *num=malloc(3*sizeof(num));
    int len=0;
    scanf("%s",num);
    while(num[len]!='\0')
    {
        len++;
    }
    if(len==1)
    {
        onedigit(num[0]);
    }
    else if(len==2)
    {
        twodigit(num[0],num[1]);
    }
    else
    {
        threedigit(num[0],num[1],num[2]);
    }
}
void onedigit(char a)
{
    switch(a)
    {
        case '1':printf("one ");
        break;
        case '2':printf("two ");
        break;
        case '3':printf("three ");
        break;
        case '4':printf("four ");
        break;
        case '5':printf("five ");
        break;
        case '6':printf("six ");
        break;
        case '7':printf("seven ");
        break;
        case '8':printf("eight ");
        break;
        case '9':printf("nine ");
        break;
    }
}
void twodigit(char a,char b)
{
    if(a=='1')
    {
        teen(b);
    }
    else
    {
        tens(a);
        onedigit(b);
    }
}
void threedigit(char a,char b,char c)
{
    onedigit(a);
    printf("hundred and ");
    twodigit(b,c);
}
void teen(char n)
{
    switch(n)
    {
        case '0':printf("ten ");
        break;
        case '1':printf("eleven ");
        break;
        case '2':printf("twelve ");
        break;
        case '3':printf("thirteen ");
        break;
        case '4':printf("fourteen ");
        break;
        case '5':printf("fifteen ");
        break;
        case '6':printf("sixteen ");
        break;
        case '7':printf("seventeen ");
        break;
        case '8':printf("eighteen ");
        break;
        case '9':printf("nineteen ");
        break;
    }
}
void tens(char n)
{
    switch(n)
    {
        case '2':printf("twenty ");
        break;
        case '3':printf("thirty ");
        break;
        case '4':printf("forty ");
        break;
        case '5':printf("fifty ");
        break;
        case '6':printf("sixty ");
        break;
        case '7':printf("seventy ");
        break;
        case '8':printf("eighty ");
        break;
        case '9':printf("ninety ");
        break;
    }
}
