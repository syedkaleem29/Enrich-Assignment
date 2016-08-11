#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node * insert(struct node *head, int data){
    if(head==NULL){
        struct node *n=(struct node *)malloc(sizeof(struct node));
        struct node *temp;
        n->data=data;
        n->left=NULL;
        n->right=NULL;
        return n;
    }
    if(data < head->data){
        head->left=insert(head->left,data);
        return head;
    }
    else{
        head->right=insert(head->right,data);
        return head;
    }
}
void printData(struct node *head){
    if(head==NULL){
        return;
    }
    printData(head->left);
    printf("%d ",head->data);
    printData(head->right);
}
int search(struct node *head,int data){
    int ans=0;
    if(head==NULL){
        return ans;
    }
    if(head->data==data){
        ans=1;
        return ans;
    }
    if(data < head->data){
        ans=search(head->left,data);
    }
    else{
        ans=search(head->right,data);
    }
    return ans;
}
int main(){
    struct node *head=(struct node *)malloc(sizeof(struct node));
    head=NULL;
    int data;
    int noOfData;
    scanf("%d",&noOfData);
    for(int i=0;i<noOfData;i++){
        scanf("%d",&data);
        head=insert(head,data);
    }
    printData(head);
    scanf("%d",&data);
    if(search(head,data)){
        printf("Data found\n");
    }
    else{
        printf("Data not found\n");
    }
    return 0;
}
