#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
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
int pop(struct node** top )
{
    if((*top)==NULL)
    {
        
        return 9999;
    }
    else
    {
        int k;
        k=(*top)->data;
        struct node* p=(*top);
        (*top)=(*top)->next;
        free(p);
        return k;
    }
}
int call(struct node*top)
{
    if(top==NULL)
    {
        return 9999;
    }
    else
    {
        return top->data;
    }
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        struct node* stack1=NULL;
        struct node* stack2=NULL;
        while(n--)
        {
            int a;
            scanf("%d", &a);
            push(&stack1,a);
        }
        while(stack1!=NULL)
        {
            int a;
            a=pop(&stack1);
            
            while((stack2!=NULL)&&((call(stack2))<a))
            {
                push(&stack1,pop(&stack2));
            }
            push(&stack2,a);
        }
        struct node* p=stack2;
        while(p!=NULL)
        {
            printf("%d ", p->data);
            
            p=p->next;
        }
        printf("\n");
        
    }
    return 0;
}