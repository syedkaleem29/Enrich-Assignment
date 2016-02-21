#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node* linknum(struct node *,int);
struct node* add_to(struct node *,int num);
struct node* add(struct node *,struct node *,struct node *);
struct node* reverse(struct node *);
void print(struct node *);
int main()
{
    struct node *head1=(struct node *)malloc(sizeof(struct node));
    struct node *head2=(struct node *)malloc(sizeof(struct node));
    struct node *head3=(struct node *)malloc(sizeof(struct node));
    head1=NULL;
    head2=NULL;
    head3=NULL;
    int num1,num2;
    scanf("%d",&num1);
    scanf("%d",&num2);
    head1=linknum(head1,num1);
    head2=linknum(head2,num2);
    head3=add(head1,head2,head3);
    head3=reverse(head3);
    print(head3);
    return 0;
}
struct node* linknum(struct node *head,int num)
{
    int r;
    while(num>0)
    {
        r=num%10;
        head=add_to(head,r);
        num=num/10;
    }
    return head;
}
struct node* add_to(struct node *head,int num)
{
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    struct node *temp;
    ptr->data=num;
    ptr->next=NULL;
    if(head==NULL)
    {
        head=ptr;
        return head;
    }
    temp=head;
    while(temp->next)
    {
        temp=temp->next;
    }
    temp->next=ptr;
    return head;
}
void print(struct node *head)
{
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    ptr=head;
    while(ptr!=NULL)
    {
        printf("%d",ptr->data);
        ptr=ptr->next;
    }
}
struct node* add(struct node *head1,struct node *head2,struct node *head3)
{
    struct node *ptr1=head1;
    struct node *ptr2=head2;
    int sum=0,carry=0,digit;
    while(ptr1!=NULL||ptr2!=NULL)
    {
        sum=0;
        if(ptr1!=NULL)
        {
            sum+=ptr1->data;
            ptr1=ptr1->next;
        }
        if(ptr2!=NULL)
        {
            sum+=ptr2->data;
            ptr2=ptr2->next;
        }
        sum+=carry;
        digit=sum%10;
        carry=sum/10;
        head3=add_to(head3,digit);
    }
    if(carry!=0)
    {
        head3=add_to(head3,carry);
    }
    return head3;
}
struct node* reverse(struct node *head)
{
    struct node *temp1;
    struct node *temp2;
    temp1=head->next;
    head->next=NULL;
    while(temp1!=NULL)
    {
        temp2=temp1->next;
        temp1->next=head;
        head=temp1;
        temp1=temp2;
    }
    return head;
}
