#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
struct node{
    char roll[15];
    struct node* next;
};
struct link{
    struct node* link;
    struct link* nextlink;
    struct link* prevlink;
};
void push(struct node** top, char str[])
{
    struct node* p=(struct node*)malloc(sizeof(struct node));
    strcpy(p->roll,str);
    p->next=(*top);
    (*top)=p;
}
 
int main()
{
    int t;
    scanf("%d",&t);
    for(;t>0;t--)
    {
        int n,k,i;
        scanf("%d%d", &n, &k);
        struct node* head=NULL;
        for(i=0;i<n;i++)
        {
            char str[15];
            scanf("%s", str);
            push(&head,str);
        }
        struct link* start=NULL;
        
       for(i=0;i<k;i++)
        {
            if(start==NULL)
            {
                start=(struct link*)malloc(sizeof(struct link));
        start->link=NULL;
        start->nextlink=start;
        start->prevlink=start;
            }
            else
            {
                struct link* p=(struct link*)malloc(sizeof(struct link));
                p->link=NULL;
                start->prevlink->nextlink=p;
                p->nextlink=start;
                start->prevlink=p;
            }
              
        }
        struct link* first=start;
        for(i=0;i<n;i++)
        {
            
            char word[15];
            struct node* m=head;
            strcpy(word,head->roll);
                head=head->next;
                free(m);
            push(&(start->link) ,word);
            start=(start->nextlink);
           
        }
        
        while(n>0)
        {
            struct link* w=first;
            char word[15];
            if(w->link!=NULL)
            strcpy(word,w->link->roll);
            else
            {struct link* p=w;
            while(p->link==NULL)
            p=p->nextlink;
            strcpy(word,p->link->roll);
            }
            for(i=0;i<k;i++)
            {
                if(w->link!=NULL)
                {
                    if(strcmp(word,w->link->roll)>0)
                    {
                        strcpy(word,w->link->roll);
                    }
                }
                w=w->nextlink;
            }
            w=first;
            for(i=0;i<k;i++)
            {
                if(w->link!=NULL)
                {
                    if(strcmp(word,w->link->roll)==0)
                    {
                        printf("%s\n", w->link->roll);
                        n--;
                        struct node* c=w->link;
                        (w->link)=(c->next);
                        free(c);
                        break;
                    }
                }
                w=w->nextlink;
            }
        }
        
        
    }
    return 0;
}