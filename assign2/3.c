#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    int data;
    struct node* next;
    
};
void push(struct node** top, int a)
{
    struct node* p=(struct node*)malloc(sizeof(struct node));
    p->data=a;
    p->next=(*top);
    (*top)=p;
}
void call(struct node*top)
{
    if(top==NULL)
    {
        printf("stack underflow\n");
    }
    else
    {
        printf("%d\n", top->data );
    }
}
void pop(struct node** top)
{
    if((*top)==NULL)
    {
        printf("stack underflow\n");
    }
    else
    {
        printf("%d\n", (*top)->data);
        struct node* p=(*top);
        (*top)=(*top)->next;
        free(p);
    }
}
int main()
{
    int t;
    scanf("%d", &t);
    for(;t>0;t--)
    {
        int n;
        scanf("%d", &n);
        struct node* top=NULL;
        char PUSH[]="push";
        char POP[]="pop";
        char CALL[]="top";
        for(;n>0;n--)
        {
            char comm[6];
            scanf("%s", comm);
            if(strcmp(PUSH,comm)==0)
            {
                int a;
                scanf("%d", &a);
                push(&top,a);
            }
            else if(strcmp(POP,comm)==0)
            {
                pop(&top);
            }
            else if(strcmp(CALL,comm)==0)
            {
                call(top);
            }
        }
        
    }
    return 0;
}