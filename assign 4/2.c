#include<stdio.h>
#include<stdlib.h>
struct adjlist{
    int adjv;
    struct adjlist* next;
};
struct node{
    int data;
    struct node* next;
    
};

void insertbeginning(struct adjlist **start, int a,struct adjlist **last)
{
    struct adjlist* p=(struct adjlist*)malloc(sizeof(struct adjlist));
    p->adjv =a;
    p->next= *start;
    *start= p;
    if((*last)==NULL)
    *last=p;
}
void insertlast(struct adjlist **head, int a,struct adjlist **last)
{
    
    struct adjlist* p=(struct adjlist*)malloc(sizeof(struct adjlist));
    p->adjv=a;
    p->next=NULL;
    (*last)->next=p;
    *last=p;
}
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
int dequeue(struct node **front, struct  node** last)
{
    if((*front)==(*last))
    (*last)=NULL;
    if((*front)==NULL)
    return -1;
    else
    {
        int k=(*front)->data;
        struct node* p=(*front);
        *front=(*front)->next;
        free(p);
        return k;
        
    }
}
void BFS(struct adjlist* list[], int v)
{
    int visited[v];
  //  int costfroms[v];
    struct node* paths[v];
    struct node* pathlast[v];
    for(int i;i<v;i++)
   { visited[i]=0;
     //   costfroms[i]=-1;   
       paths[i]=NULL;
       pathlast[i]=NULL;
   }
    
    struct node* queue=NULL;
    struct node* queuelast=NULL;
    enqueue(&queuelast,0,&queue);
    visited[0]=1;
  //  costfroms[0]=0;
    enqueue(&pathlast[0],0,&paths[0]);
    while(queue!=NULL)
    {int k=dequeue(&queue,&queuelast);
    struct adjlist* p=list[k];
    while(p!=NULL)
    {
        if(visited[p->adjv]==0)
        {
            visited[p->adjv]=1;
            enqueue(&queuelast,p->adjv,&queue);
          //  costfroms[p->adjv]=costfroms[k]+1;
            struct node* f=paths[k];
            while(f!=NULL)
            {
                enqueue(&pathlast[p->adjv],f->data,&paths[p->adjv]);
                f=f->next;
            }
            enqueue(&pathlast[p->adjv],p->adjv,&paths[p->adjv]);
        }
        p=p->next;
    }
    }
    
     for(int i=0;i<v;i++)
     {
         struct node* s=paths[i];
         if(s==NULL)
         printf("NIL");
         while(s!=NULL)
         {
             printf("%d ", s->data);
             s=s->next;
         }
         printf("\n");
     }
    
}


int main()
{
    int t;
    scanf("%d", &t);
    for(;t>0;t--)
    {
        int v, e;
        scanf("%d%d", &v, &e);
        struct adjlist* list[v]; struct adjlist* listlast[v];
        for(int i=0;i<v;i++)
        {
            list[i]=NULL;
            listlast[i]=NULL;
        }
        int k;
        for(k=0;k<e;k++)
        {
            int x,y;
            scanf("%d%d", &x, &y);
            if(list[x]==NULL)
            insertbeginning(&list[x],y,&listlast[x]);
            else
            insertlast(&list[x],y,&listlast[x]);
        }
        BFS(list,v);
        
        
    }
    return 0;
}