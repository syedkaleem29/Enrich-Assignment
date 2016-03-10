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
void postorder(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}
int leaf(struct node *root)
{
    int res=0;
    if(root==NULL)
    {
        return res;
    }
    if(root->left==NULL && root->right==NULL)
    {
        res=1;
    }
    return res;
}
int isSum(struct node *node)
{
    int leftsum=0,rightsum=0,sum=0;
    if(node==NULL || leaf(node))
    {
        return 1;
    }
    if(isSum(node->left) && isSum(node->right))
    {
        if(node->left==NULL)
        {
            leftsum=0;
        }
        else if(leaf(node->left))
        {
            leftsum+=node->left->data;
        }
        else
        {
            leftsum+=2*(node->left->data);
        }
        if(node->right==NULL)
        {
            rightsum=0;
        }
        else if(leaf(node->right))
        {
            rightsum+=node->right->data;
        }
        else
        {
            rightsum+=2*(node->right->data);
        }
        sum=leftsum+rightsum;
        if(node->data==sum)
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    struct node *root=NULL;
    int res=0;
    root=create(25);
    root->left=create(10);
    root->right=create(3);
    root->left->left=create(4);
    root->left->right=create(6);
    root->right->right=create(3);
    postorder(root);
    res=isSum(root);
    if(res==1)
    {
        printf("\nThe given tree is a sum tree\n");
    }
    else
    {
        printf("\nThe given tree is not a sum tree\n");
    }
}
