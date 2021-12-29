#include<stdio.h>
#include<stdlib.h>
struct Binarytree
{
    int data;
    struct Binarytree *left,*right,*next;
}*head,*cn;
struct Binarytree *createRoot()
{
    struct Binarytree *newnode=(struct Binarytree *)malloc(sizeof(struct Binarytree));
    if (newnode==NULL)
    {
        printf("Unable to allocate the memory\n");
        exit(1);
    }
    printf("Enter the value for the node[ And enter -1 for no node ]\n");
    scanf("%d",&newnode->data);
    if (newnode->data==-1)
    {
        return NULL;
    }
    printf("Enter the data for left child\n");
    newnode->left=createRoot();
    printf("Enter the data for right node\n");
    newnode->right=createRoot();
    return newnode;
}
void preorder(struct Binarytree *root)
{
    if (root==NULL)
    {
        return;
    }
    printf("%d\n",root->data);
    preorder(root->left);
    preorder(root->right);
}
void  Inorder(struct Binarytree *root)
{
    if (root==NULL)
    {
        return;
    }
    Inorder(root->left);
    printf("%d\n",root->data);
    Inorder(root->right);
}
void postorder(struct Binarytree *root)
{
    if (root==NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d\n",root->data);
}
void binary(struct Binarytree *root)
{
    if (root==NULL)
    {
        return;
    }
    
}
int main()
{
    struct Binarytree *root=createRoot();
    // printf("PreOrder binary tree\n");
    // preorder(root);
    printf("Inorder transversal of binary tree\n");
    Inorder(root);
    printf("Binary search representation of tree\n");
    binary(root);
    // printf("PostOrder transversal of binary tree\n");
    // postorder(root);
    return 0;
}