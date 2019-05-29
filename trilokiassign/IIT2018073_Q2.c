#include <stdio.h>
#include <stdlib.h>
struct node{
int data;
struct node* left;
struct node* right;
};
struct node* inserter(struct node* root, int a )
{
    if(root==NULL)
    {
         root=(struct node*)malloc(sizeof(struct node));
        root->data=a;
        root->left=NULL;
        root->right=NULL;
        return root;
    }
    else{
        if(a<root->data)
            root->left= inserter(root->left,a);
        else
        root->right= inserter(root->right,a);
        return root;
    }
};
struct node* finder(struct node* root, int a)
{
    if(root==NULL||root->data==a)
        return root;
        if(a<root->data)
        return finder(root->left,a);
         return finder(root->right,a);



};
void inorder(struct node* root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
int main()
{
    struct node* root=NULL;
    int array[]={19, 22, 13, 7, 24, 17, 11, 3, 39, 51 };

    for(int i=0;i<10;i++)
    {
         root=inserter(root,array[i]);
    }

   if(finder(root,4)==NULL)
        printf("not found \n");
    else
        printf("found element\n");

    inorder(root);
    return 0;
}
