#include<stdio.h>
#include<malloc.h>
struct node {
    int data;
    int sumnext;
    struct node* next;
    
};
void insertbeginning (struct node **start, int a)
{
  struct node *p= (struct node*)malloc(sizeof(struct node));
  p->data=a;
  p->sumnext=0;
  p->next=*start;
  *start=p;
}
void insertlast( struct node **head, int a )
{
    struct node *k = *head;
    struct node *p= (struct node *)malloc(sizeof(struct node));
    p->data=a;
    p->sumnext=0;
    p->next=NULL;
    while(k->next!=NULL)
    {
        k=k->next;
    }
    k->next=p;
}
void printlist(struct node* p)
{
    while(p!=NULL)
    {
        printf("%d ", p->data);
        p=p->next;
        
    }
    printf("\n");
}
void deleteelement(struct node **head, int a)
{
    struct node* lazy=NULL;
    struct node* p=*head;
    while(p!=NULL)
    {
        if(p->data==a)
        {
            if(p== *head)
            {
                *head=p->next;
                free(p);
                break;
            }
            else
            {
                lazy->next=p->next;
                free(p);
            }
        }
        lazy=p;
        p=p->next;
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
        int i,a;
        int s;
        scanf("%d", &s);
        scanf("%d", &a);
        struct node* head=NULL;
        insertbeginning(&head, a);
        for(i=0;i<n-1;i++)
        {
            scanf("%d", &a);
            insertlast(&head, a);
        }
        struct node* k=head;
        printlist(head);
        while(k!=NULL)
        {
            
            if(k!=NULL)
            {
                struct node* q= k;
                for(i=0;i<s;i++)
                {
                  
                    k->sumnext=(k->sumnext)+(q->data);
                        if(q->next!=NULL)
                            {q=q->next;
                            }
                            else
                            break;
                }
            }
            //printf("  %d  ", k->sumnext);
            k=k->next;
        }
       // printf("\n");
        k=head;
        int max=0;
        while(k!=NULL)
        {
            if((k->sumnext)>max)
            {
                max= k->sumnext;
            }
            k=k->next;
        }
       
       // printlist(head);
         k=head;
         struct node* head2=NULL;
        while(k!=NULL)
        {
            if(k->sumnext==max)
            {
                insertbeginning(&head2, k->data);
                deleteelement(&head, k->data);
                k=k->next;
                for(i=1;i<s;i++)
                {
                    insertlast(&head2, k->data);
                    deleteelement(&head, k->data);
                    k=k->next;
                }
                
                break;
            }
            k=k->next;
        }
        printlist(head);
        printlist(head2);
        
    }
    return 0;
}