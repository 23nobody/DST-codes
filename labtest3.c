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
void insertbeginning(struct adjlist **start, int a,struct adjlist **last)
{
    struct adjlist* p=(struct adjlist*)malloc(sizeof(struct adjlist));
    p->adjv =a;
    p->weight=1;
    p->next= *start;
    *start= p;
    if((*last)==NULL)
    {
    p->next=NULL;    
    (*last)=(*start);
    }
}
void insertlast(struct adjlist **head, int a,struct adjlist **last)
{
    
    struct adjlist* p=(struct adjlist*)malloc(sizeof(struct adjlist));
    p->adjv=a;
    p->weight=1;
    p->next=NULL;
   
  
   (*last)->next=p;
    (*last)=p;
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
void dijkstra(struct adjlist* list[], int v,int source,int dest)
{
    int path[v];
    int parent[v];
    //int costfroms[v];
    for(int i;i<v;i++)
   { path[i]=-1;
    parent[i]=source;
       // costfroms[i]=-1;   
       
   }
    
    struct node* queue=NULL;
    struct node* queuelast=NULL;
    enqueue(&queuelast,source,&queue);
    path[source]=0;
    parent[source];
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
         else if((path[k]+p->weight)>path[p->adjv])
        {
           // path[p->adjv]=path[k]+p->weight;
            parent[p->adjv]=k;
           // enqueue(&queuelast,p->adjv,&queue);
        }
        p=p->next;
        }
    }
        if(path[dest]==-1)
        printf("no\n");
        else
        printf("yes\n");
    
        
    
}
 
int main()
{
    int t;
    scanf("%d", &t);
    for(;t>0;t--)
    {
        int v,e;
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
            if(list[y]==NULL)
            insertbeginning(&list[y],x,&listlast[y]);
            else
            insertlast(&list[y],x,&listlast[y]);
        }
        int q;
        scanf("%d", &q);
        for(int i=0;i<q;i++)
        {
            int xindex,yindex;
            scanf("%d%d", &xindex,&yindex);
            if(xindex>=v||yindex>=v)
            printf("no\n");
            else
            dijkstra(list,v,xindex,yindex);
        }
        
    }
    return 0;
}
