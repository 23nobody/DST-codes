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
        int n,i,q;
        scanf("%d%d", &n, &q);
        struct node* head[q];
        struct node* last[q];
        float value[q];
        float size[q];
        float checker[q];
        for(i=0;i<q;i++)
        {
            
            size[i]=0;
            head[i]=NULL;
            last[i]=NULL;
            scanf("%f", &value[i]);
            checker[i]=((size[i])/2)+((value[i])/2);
           // printf("    %f  %f  %f  %d  \n  ", checker[i], size[i], value[i], i);
        }
        for(i=0;i<n;i++)
        {
            int j;
            float min=1000000;
            for(j=0;j<q;j++)
            {
                if(checker[j]<min)
                {
                    min=checker[j];
                }
            }
            
            for(j=0;j<q;j++)
            {
                if(min==checker[j])
                break;
            }
            char name[20];
            char gen[20];
            char city[20];
            char con[20];
            scanf("%s%s%s%s", name, gen, city, con);
            push(&head[j],name,gen,city,con, &last[j]);
            size[j]++;
            checker[j]=((size[j])/2)+(value[j]/2);
           // printf("    %f  %f  %f  %d    ", checker[j],size[j],value[j],j );
        }
        while(n>0)
        {
            for(i=0;i<q;i++)
            {
                if(head[i]!=NULL)
                {
                 printf("%s %s %s %s\n", head[i]->name, head[i]->gen, head[i]->city, head[i]->con);
                 head[i]=head[i]->next;
                 n--;
                }
            }
        }
        
        
        
    }
    return 0;
}
