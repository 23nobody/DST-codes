#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
struct node
{
    char roll[15];
    struct node* next;
    
};
void push(struct node** top, char word[])
{
    struct node* p=(struct node*)malloc(sizeof(struct node));
    strcpy(p->roll,word);
    p->next=(*top);
    (*top)=p;
}
int main()
{
    int t;
    scanf("%d", &t);
    for(;t>0;t--)
    {
        int n,k;
        scanf("%d%d", &n, &k);
        int i,j;
        struct node* head=NULL;
        for(i=0;i<n;i++)
        {
            char roll[15];
            scanf("%s", roll);
            push(&head,roll);
        }
        int p,r;
        if(n%k==0)
        {
            p=n/k;
        }
        else
        p=(n/k)+1;
        struct node* classroom[p];
        for(i=0;i<p;i++)
        {
            classroom[i]=NULL;
        }
        r=0;
        for(i=0;(i<n)&&(head!=NULL)&&(r<p);)
        {
            
            for(j=0;(j<k)&&(head!=NULL);j++)
            {
                char word[15];
                struct node* m=head;
               
                strcpy(word,head->roll);
                head=head->next;
                free(m);
                push(&classroom[r],word);
                
                i++;
            }
            r++;
        }
        for(i=0;i<p;i++)
        {
            while(classroom[i]!=NULL)
            {
            printf("%s\n", classroom[i]->roll);
            classroom[i]=classroom[i]->next;
            }
        }
    }
    return 0;
}
