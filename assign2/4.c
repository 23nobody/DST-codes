#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    int data;
    struct node* next;
    
};
void enqueue(struct node** last, int a,struct node **front)
{
    struct node* p=(struct node*)malloc(sizeof(struct node));
    p->data=a;
    p->next=NULL;
    if((*last)!=NULL)
    (*last)->next=p;
    (*last)=p;
    if((*front)==NULL)
    {
        (*front)=p;
    }
}
void dequeue(struct node** front,struct node** last)
{
    if((*front)==(*last))
    (*last)=NULL;
    if((*front)==NULL)
    {
        printf("queue underflow\n" );
        
    }
    else
    {
        printf("%d\n", (*front)->data);
        struct node*p =*front;
        *front=(*front)->next;
        free(p);
    }
}
void call(struct node* front)
{
    if(front==NULL)
    {
        printf("queue underflow\n");
    }
    else
    {
        printf("%d\n", front->data);
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
        struct node* front=NULL;
        struct node* last=NULL;
        char en[]="enqueue";
        char de[]="dequeue";
        char fr[]="front";
        for(;n>0;n--)
        {
            char comm[10];
            scanf("%s", comm);
            if(strcmp(en,comm)==0)
            {
                int a;
                scanf("%d", &a);
                enqueue(&last,a,&front);
            }
            else if(strcmp(de,comm)==0)
            {
                dequeue(&front,&last);
            }
            else if(strcmp(fr,comm)==0)
            {
                call(front);
            }
        }
    }
    return 0;
}