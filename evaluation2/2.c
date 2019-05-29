#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
struct node{
    char name[20];
    char gen[20];
    char city[20];
    char con[20];
    int index;
    struct node* next;
};
void push(struct node** head, char name[], char gen[], char city[], char con[],struct node** last)
{
    struct node* p=(struct node*)malloc(sizeof(struct node));
    strcpy(p->name,name);
    strcpy(p->gen,gen);
    strcpy(p->city,city);
    strcpy(p->con,con);
    if(*head==NULL)
    {
        *head=p;
        *last=p;
    }
    else
    {
        (*last)->next=p;
        *last=p;
    }
}
void printlist(struct node* p)
{
    while(p!=NULL)
    {
        printf("%s %s %s %s\n", p->name, p->gen, p->city, p->con);
        p=p->next;
    }
}
void erase(struct node** lazy,struct node** p)
{
   ( (*lazy)->next)=((*p)->next);
}
int main()
{
    int t;
    scanf("%d", &t);
    for(;t>0;t--)
    {
        int n,i;
        scanf("%d", &n);
        struct node* head=NULL;
        struct node* last=NULL;
        for(i=0;i<n;i++)
        {
            char name[20];
            char gen[20];
            char city[20];
            char con[20];
            scanf("%s%s%s%s", name, gen, city, con);
            push(&head,name,gen,city,con, &last);
        }
        while(n--)
        {
            int a;
            scanf("%d", &a);
            struct node* p=head;
            struct node* lazy=NULL;
            i=0;
            while(i!=a)
            {
               
                lazy=p;
                 p=p->next;
                i++;
            }
            printf("%s %s %s %s\n", p->name, p->gen, p->city, p->con);
            if(p==head)
            {
             head=head->next;
            }
            else
            {
               // printf("mai yaha hoon");
                erase(&lazy,&p);
                
            }
            //printlist(head);
        }
        
    }
    return 0;
}