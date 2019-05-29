#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct vertex{
    char name[50];
    int index;
    struct vertex* next;
};
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
    {
    p->next=NULL;    
    (*last)=(*start);
    }
}
void insertlast(struct adjlist **head, int a,struct adjlist **last,int w)
{
    
    struct adjlist* p=(struct adjlist*)malloc(sizeof(struct adjlist));
    p->adjv=a;
    p->weight=w;
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
void print(int parent[],int vertex,int path[],char names[500][500])
{
    if(path[vertex]==-1)
    printf("NIL ");
    else
    {
    if(parent[vertex]!=-1)
    print(parent,parent[vertex],path,names);
    printf("%s ", names[vertex]);
    }
}
void dijkstra(struct adjlist* list[], int v,int source,int dest, char names[500][500])
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
    parent[source]=-1;
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
            if(strcmp(names[k],names[(parent[p->adjv])])<0)
            {
                 path[p->adjv]=path[k]+p->weight;
            parent[p->adjv]=k;
            enqueue(&queuelast,p->adjv,&queue);
            }
        }
        p=p->next;
        }
    }
     print(parent,dest,path, names);
      printf("\n");
       // printf("%d\n", path[dest]);
    
        
    
}

int main()
{
    int t;
    scanf("%d", &t);
    for(;t>0;t--)
    {
        int v, e;
        scanf("%d%d", &v, &e);
        char names[500][500];
        for(int i=0;i<v;i++)
        {
            char name[50];
            scanf("%s", name);
           strcpy(names[i],name);
        }
        
         struct adjlist* list[v]; struct adjlist* listlast[v];
         for(int i=0;i<v;i++)
        {
            list[i]=NULL;
            listlast[i]=NULL;
        }
        int k;
         for(k=0;k<e;k++)
        {
            char x[50], y[50];
            int w;
            scanf("%s%s%d", x, y, &w);
            int xindex=-1, yindex=-1;
            for(int i=0;i<v;i++)
            {
               
                if(strcmp(names[i],x)==0)
                xindex=i;
                if(strcmp(names[i],y)==0)
                yindex=i;
                
                
            }
           // printf("%d %d\n", xindex, yindex);
            if(list[xindex]==NULL)
            insertbeginning(&list[xindex],yindex,&listlast[xindex],w);
            else
            insertlast(&list[xindex],yindex,&(listlast[xindex]),w);
        }
         int q;
        scanf("%d", &q);
       for(int i=0;i<q;i++)
        {
            int xindex=-1, yindex=-1;
            char source[50],dest[50];
            scanf("%s%s", source, dest);
            
           for(int i=0;i<v;i++)
            {
               
                if(strcmp(names[i],source)==0)
                xindex=i;
                if(strcmp(names[i],dest)==0)
                yindex=i;
                
                
            }
            dijkstra(list,v,xindex,yindex,names);
        }
        
    }
    return 0;
}