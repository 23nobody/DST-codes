#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void insert(int** first, int a,int *last)
{
    if(*first==last)
    {
        printf("stack overflow\n");
    }
    else
    {
    (*first)++;
     **first=a;
    }
}
void takeout(int **first, int* low )
{
    if(*first==low)
    {
        printf("stack underflow\n");
    }
    else
    {
    printf("%d\n", **first);
   ( *first)--;
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
        int s;
        scanf("%d", &s);
        int array[s];
        int* first= &array[-1];
        
        char push[]="push";
        char pop[]="pop";
        char top[]="top";
        for(;n>0;n--)
        {
            char comm[6];
            scanf("%s", comm);
            if(strcmp(comm,push)==0)
            {
                int a;
                scanf("%d", &a);
                insert(&first,a,&array[s-1] );
            }
            else if(strcmp(comm,pop)==0)
            {
                takeout(&first, &array[-1]);
            }
            else if(strcmp(comm,top)==0)
            {
                if(first!=&array[-1])
                printf("%d\n", *first);
                else
                printf("stack underflow\n");
            }
        }
        
    }
    return 0;
}
