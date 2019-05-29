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
        int n,i;
        scanf("%d", &n);
        struct node* head=NULL;
        for(i=0;i<n;i++)
        {
            char name[20];
            char gen[20];
            char city[20];
            char con[20];
            scanf("%s%s%s%s", name, gen, city, con);
            push(&head,name,gen,city,con);
        }
        printlist(head);
        
    }
    return 0;
}
