#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *create(int value)
{
    struct node *root=(struct node *)malloc(sizeof(struct node));
    root->data=value;
    root->left=NULL;
    root->right=NULL;
    return root;
}
struct node *insert(struct node *root,int value)
{
    if(root==NULL)
    {
        return create(value);
    }
    if(value<root->data)
    {
        root->left=insert(root->left,value);
    }
    if(value>root->data)
    {
        root->right=insert(root->right,value);
    }
    return root;
}
void Inorder(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
    Inorder(root->left);
    printf("%d ",root->data);
    Inorder(root->right);
}
int leaf(struct node *node)
{
    int is=0;
    if(node==NULL)
    {
        return is;
    }
    if(node->left==NULL && node->right==NULL)
    {
        is=1;
    }
    return is;
}
int sum(struct node *root)
{
    int s=0;
    if(root!=NULL)
    {
        if(leaf(root->left))
        {
            s+=root->left->data;
        }
        else
        {
            s+=sum(root->left);
        }
        s+=sum(root->right);
    }
    return s;
}
int main()
{
    struct node *root=NULL;
    int res,i,n,value;
    printf("Print the number of values\n");
    scanf("%d",&n);
    printf("Enter the value\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&value);
        root=insert(root,value);
    }
    Inorder(root);
    res=sum(root);
    printf("sum:%d\n",res);
}
