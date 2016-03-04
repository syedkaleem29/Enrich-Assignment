#include<stdio.h>
#include<stdlib.h>
int year_in(char *);
int month_in(char *);
char* month_in_name(int);
int day_in(char *);
int day_index(char *);
char* day_in_name(int,int,int);
char* day_before_n(int,char *);
int days_between(char *,char *);
char* convert(int,int,int);
int main()
{
    char *date=malloc(10*sizeof(char));
    char *newdate=malloc(10*sizeof(char));
    char *month_name,*day_name,*nDaysBefore;
    int year,preyear,month,preMonth,day,dayIndex,difference,n;
    printf("Enter date:\n");
    scanf("%s",date);
    printf("Enter new date:\n");
    scanf("%s",newdate);
    printf("Enter n:\n");
    scanf("%d",&n);
    year=year_in(date);
    printf("Year: %d\n",year);
    preyear=year-1;
    printf("Previous Year: %d\n",preyear);
    month=month_in(date);
    printf("Month in number: %d\n",month);
    preMonth=(month-1==0)?12:month-1;
    month_name=month_in_name(month);
    printf("Month in name: %s\n",month_name);
    month_name=month_in_name(preMonth);
    printf("Previous month in name: %s\n",month_name);
    day=day_in(date);
    printf("Day in number: %d\n",day);
    dayIndex=day_index(date);
    printf("Day index is: %d\n",dayIndex);
    nDaysBefore=day_before_n(n,date);
    printf("Day before %d days: %s\n",n,nDaysBefore);
    difference=days_between(date,newdate);
    printf("Days between:%d\n",difference);
    day_name=day_in_name(year,month,day);
    printf("Day name is: %s",day_name);
    return 0;
}
int year_in(char *date)
{
    int y1,y2,y3,y4,year;
    y1=(date[0]-'0')*1000;
    y2=(date[1]-'0')*100;
    y3=(date[2]-'0')*10;
    y4=(date[3]-'0');
    year=y1+y2+y3+y4;
    return year;
}
int month_in(char *date)
{
    int m1,m2,mon;
    m1=(date[5]-'0')*10;
    m2=(date[6]-'0');
    mon=m1+m2;
    return mon;
}
char* month_in_name(int month)
{
    char *name=malloc(sizeof(char));
    switch(month)
    {
        case 1:name="January";break;
        case 2:name="February";break;
        case 3:name="March";break;
        case 4:name="April";break;
        case 5:name="May";break;
        case 6:name="June";break;
        case 7:name="July";break;
        case 8:name="August";break;
        case 9:name="September";break;
        case 10:name="October";break;
        case 11:name="November";break;
        case 12:name="December";break;
    }
    return name;
}
int day_in(char *date)
{
    int d1,d2,day;
    d1=(date[8]-'0')*10;
    d2=(date[9]-'0');
    day=d1+d2;
    return day;
}
int day_index(char *date)
{
    int year=year_in(date);
    int month=month_in(date);
    int day=day_in(date);
    int nodays[]={31,28,31,30,31,30,31,31,30,31,30,31};
    int i,sum=0;
    if((year%400==0)||(year%4==0 &&year%100!=0))
    {
        nodays[1]=29;
    }
    for(i=0;i<month-1;i++)
    {
        sum=sum+nodays[i];
    }
    sum=sum+day;
    return sum;
}
char* day_before_n(int n,char *date)
{
    char *newdate=malloc(sizeof(char));
    int year=year_in(date),i;
    int month=month_in(date);
    int day=day_in(date);
    int noday[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    if((year%400==0)||(year%4==0 &&year%100!=0))
    {
        noday[1]=29;
    }
    if(day>n)
    {
        day=day-n;
    }
    else
    {
        n=n-day;
        for(i=month-1;;i--)
        {
            if(n>noday[i])
            {
                n=n-noday[i];
            }
            else
            {
                day=noday[month]-n;
                month=i;
                break;
            }
        }
    }
    newdate=convert(year,month,day);
    return newdate;
}
int days_between(char *date,char *newdate)
{
    int dindex1=day_index(date);
    int dindex2=day_index(newdate);
    int year1=year_in(date);
    int year2=year_in(newdate);
    int i,s=0;
    if(year1>year2)
    {
        year2=year1+year2-(year1=year2);
    }
    for(i=year1+1;i<year2;i++)
    {
        if((i%400==0)||(i%4==0 && i%100!=0))
        {
            s+=366;
        }
        else
        {
            s+=365;
        }
    }
    if((year1%400==0)||(year1%4==0 && year1%100!=0))
    {
        dindex1=366-dindex1;
    }
    else
    {
        dindex1=365-dindex1;
    }
    return s+dindex1+dindex2;
}
char* day_in_name(int year,int month,int day)
{
    char *dayn=malloc(sizeof(char));
    int ans,rem,last=year%100,cen=year/100;
    int newmon[]={0,11,12,1,2,3,4,5,6,7,8,9,10};
    if(month==1 || month==2)
    {
        last=last-1;
    }
    ans=day+((13*newmon[month]-1)/5)+last+(last/4)+(cen/4)-(2*cen);
    if(ans>=0)
    {
        rem=ans%7;
    }
    else
    {
        ans=-ans;
        rem=ans%7;
        rem=7-rem;
    }
    switch(rem)
    {
        case 0:dayn="Sunday";break;
        case 1:dayn="Monday";break;
        case 2:dayn="Tuesday";break;
        case 3:dayn="Wednesday";break;
        case 4:dayn="Thursday";break;
        case 5:dayn="Friday";break;
        case 6:dayn="Saturday";break;
    }
    return dayn;
}
char* convert(int year,int month,int day)
{
    char *newdate=malloc(10*sizeof(char));
    int i;
    i=3;
    while(year>0)
    {
       newdate[i]=(year%10)+48;
       year=year/10;
       i--;
    }
    newdate[4]='-';
    i=6;
    if(month<10)
    {
        newdate[5]='0';
    }
    while(month>0)
    {
       newdate[i]=(month%10)+48;
       month=month/10;
       i--;
    }
    newdate[7]='-';
    i=9;
    if(day<10)
    {
        newdate[8]='0';
    }
    while(day>0)
    {
       newdate[i]=(day%10)+48;
       day=day/10;
       i--;
    }
    return newdate;
}
