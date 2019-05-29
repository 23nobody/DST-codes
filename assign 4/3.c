#include<stdio.h>
#include<stdlib.h>
struct adjlist{
    int adjv;
    int weight;
    struct adjlist* next;
};
struct node{
    int data;
    struct node* next;
    
};

void insertbeginning(struct adjlist **start, int a,struct adjlist **last,int w)
{
    struct adjlist* p=(struct adjlist*)malloc(sizeof(struct adjlist));
    p->adjv =a;
    p->weight=w;
    p->next= *start;
    *start= p;
    if((*last)==NULL)
    *last=p;
}
void insertlast(struct adjlist **head, int a,struct adjlist **last,int w)
{
    
    struct adjlist* p=(struct adjlist*)malloc(sizeof(struct adjlist));
    p->adjv=a;
    p->weight=w;
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
void dijkstra(struct adjlist* list[], int v)
{
    int path[v];
    int parent[v];
    //int costfroms[v];
    for(int i;i<v;i++)
   { path[i]=-1;
    parent[i]=0;
       // costfroms[i]=-1;   
       
   }
    
    struct node* queue=NULL;
    struct node* queuelast=NULL;
    enqueue(&queuelast,0,&queue);
    path[0]=0;
    //costfroms[0]=0;
    while(queue!=NULL)
    {
        int k=dequeue(&queue,&queuelast);
    struct adjlist* p=list[k];
        while(p!=NULL)
        {
        if(path[p->adjv]==-1)
        {
            path[p->adjv]=path[k]+p->weight;
            parent[p->adjv]=k;
            enqueue(&queuelast,p->adjv,&queue);
           // costfroms[p->adjv]=costfroms[k]+1;
        }
        else if((path[k]+p->weight)<path[p->adjv])
        {
            path[p->adjv]=path[k]+p->weight;
            parent[p->adjv]=k;
            enqueue(&queuelast,p->adjv,&queue);
        }
        else if((path[k]+p->weight)==path[p->adjv])
        {
            if(k<parent[p->adjv])
            {
                 path[p->adjv]=path[k]+p->weight;
            parent[p->adjv]=k;
            enqueue(&queuelast,p->adjv,&queue);
            }
        }
        p=p->next;
        }
    }
    for(int i=0;i<v;i++)
    {
        printf("%d\n", path[i]);
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
            int x,y,w;
            scanf("%d%d%d", &x, &y, &w);
            if(list[x]==NULL)
            insertbeginning(&list[x],y,&listlast[x],w);
            else
            insertlast(&list[x],y,&listlast[x],w);
        }
        dijkstra(list,v);
        
        
    }
    return 0;
}