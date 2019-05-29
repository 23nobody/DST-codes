#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void insert(int *size, int a, int max, int* first)
{
 if(*size==max)
    {
        printf("queue overflow\n");
    }
    else
    {
        *(first+(*size))=a;
        (*size)++;
    }   
}
void takeout(int* first, int* size)
{
    if(*size>0)
    {
        printf("%d\n", *first);
        int i;
        for(i=0;i<(*size)-1;i++)
        {
            *(first+i)=*(first+i+1);
        }
        (*size)--;
    }
    else
    {
        printf("queue underflow\n");
    }
    
}
int main()
{
    int t;
    
    scanf("%d", &t);
    for(;t>0;t--)
    {
        int n,s;
        scanf("%d%d", &n, &s);
        int array[s];
        int size=0;
        char enqueue[]="enqueue";
        char dequeue[]="dequeue";
        char front[]="front";
        for(;n>0;n--)
        {
            char comm[9];
            scanf("%s", comm);
            if(strcmp(enqueue, comm)==0)
            {
                int a;
                scanf("%d", &a);
                insert(&size,a,s,&array[0]);
            }
            else if(strcmp(dequeue, comm)==0)
            {
                takeout(&array[0],&size);
            }
            else if(strcmp(front, comm)==0)
            {
                if(size>0)
                {
                    printf("%d\n", array[0]);
                }
                else
                {
                    printf("queue underflow\n");
                }
            }
        }
    }
    return 0;
}