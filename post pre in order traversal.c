#include<stdio.h>
#include<malloc.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct node* creatnode(int data)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
int preorder(struct node*root)
{
    if(root==NULL)

        return 0;

    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}
int inorder(struct node* root)
{
    if(root==NULL)

        return 0;

    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
int postorder(struct node* root)
{
    if(root==NULL)

        return 0;

    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}
void main()
{
    struct node* root=creatnode(6);
    root->left=creatnode(8);
    root->right=creatnode(10);
    root->left->left=creatnode(12);
    root->left->right=creatnode(4);
    root->right->left=creatnode(36);
    root->right->right=creatnode(30);
    printf("\nPreorder Traversal: \n");
    preorder(root);
    printf("\nInorder Traversal: \n");
    inorder(root);
    printf("\nPostorder Traversal: \n");
    postorder(root);

}
