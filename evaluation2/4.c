#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
struct node{
    char name[20];
    char gen[20];
    char city[20];
    char con[20];
    struct node* next;
};
void push(struct node** head, char name[], char gen[], char city[], char con[])
{
    struct node* p=(struct node*)malloc(sizeof(struct node));
    strcpy(p->name,name);
    strcpy(p->gen,gen);
    strcpy(p->city,city);
    strcpy(p->con,con);
    p->next=*head;
    *head=p;
}
void enqueue(struct node** head, char name[], char gen[], char city[], char con[],struct node** last)
{
    struct node* p=(struct node*)malloc(sizeof(struct node));
    strcpy(p->name,name);
    strcpy(p->gen,gen);
    strcpy(p->city,city);
    strcpy(p->con,con);
    p->next=NULL;
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
int main()
{
    int t;
    scanf("%d", &t);
    for(;t>0;t--)
    {
        int e,k;
        scanf("%d%d", &e, &k);
        char comm[10];
        char en[]="entering";
        char ex[]="exit";
        int size=0;
        struct node* river=NULL;
        struct node* stack=NULL;
        struct node* last=NULL;
        while(e--)
        {
            scanf("%s", comm);
            if(strcmp(en,comm)==0)
            {
                char name[20];
            char gen[20];
            char city[20];
            char con[20];
            scanf("%s%s%s%s", name, gen, city, con);
            if(size<k)
            {
                enqueue(&river,name,gen,city,con,&last);
                size++;
            }
            else
            {
                push(&stack,name,gen,city,con);
            }
            }
            else if(strcmp(ex,comm)==0)
            {
                int a;
                scanf("%d", &a);
                struct node* p=river;
                struct node* lazy=NULL;
                int i=0;
                while(i!=a)
                {
 
                lazy=p;
                 p=p->next;
                i++;
                }
            printf("%s %s %s %s\n", p->name, p->gen, p->city, p->con);
 
               if(river==p)
                {
                    if(river!=NULL)
                    {
                        if(last==river)
                            last=NULL;
                        river=(river->next);
                    }
 
                }
                else
                {
               
                 struct node* l=lazy->next;
                 lazy->next=l->next;
                 if(p==last)
                 last=lazy;
 
                }
                
                if((size>=k)&&(stack!=NULL))
                {
                enqueue(&river, stack->name, stack->gen, stack->city, stack->con,&last);
                stack=stack->next;
                size++;
                }
                size--;
               
            }
        }
 
    }
   return 0;
}
