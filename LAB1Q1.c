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
printlist(struct node* p)
{
    while(p!=NULL)
    {
        printf("%d ", p->data);
        p=p->next;
        
    }
    printf("\n");
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
        scanf("%d", &a);
        struct node* head=NULL;
        insertbeginning(&head, a);
        for(i=0;i<n-1;i++)
        {
            scanf("%d", &a);
            insertlast(&head, a);
        }
        struct node* k=head;
        while(k!=NULL)
        {
            if(k->next!=NULL)
            {
                k->sumnext=(k->data)+(k->next->data);
            }
            k=k->next;
        }
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
        k=head;
        printlist(head);
        
        while(k!=NULL)
        {
            if(k->sumnext==max)
            {
                printf("%d %d\n", k->data, k->next->data);
                break;
            }
            k=k->next;
        }
        
    }
    return 0;
}