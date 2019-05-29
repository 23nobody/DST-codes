#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node* left;
struct node* right;
};
struct node* newnode(int a)
{
    struct node* p= (struct node*)malloc(sizeof(struct node));
    p->data=a;
    p->left=NULL;
    p->right=NULL;
    return p;
}
int main()
{
    int array[]={19, 22, 13, 7, 24, 17, 11, 3, 39, 51 };
    struct node* root= newnode(array[0]);
    root->left= newnode(array[1]);
    root->right= newnode(array[2]);
    root->left->left= newnode(array[3]);
    root->left->right= newnode(array[4]);
    root->right->left= newnode(array[5]);
    root->right->right= newnode(array[6]);
    root->left->left->left= newnode(array[7]);
    root->left->left->right= newnode(array[8]);
    root->left->right->left= newnode(array[9]);
    printf("%d",(root->left->right->left->data) );
    return 0;
}
