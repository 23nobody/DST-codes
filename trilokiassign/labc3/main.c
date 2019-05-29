#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;
    printf("please enter the size of universal set:\n");
    scanf("%d", &N);
    int n1,  n2;
    printf("please enter the size of the sub sets:\n");
    scanf("%d%d", &n1, &n2);
    int arr1[N] ;
    int arr2[N] ;
    int uni[N] ;
    int inter[N] ;
    for(int i=0;i<N;i++)
    {
        arr1[i]=0;
        arr2[i]=0;
        uni[i]=0;
        inter[i]=0;

    }
    printf("enter set 1:\n");
    for(int i=0;i<n1;i++)
    {
        int a;
        scanf("%d", &a);
        arr1[a-1]=1;
    }
     printf("enter set 2:\n");
     for(int i=0;i<n2;i++)
    {
        int a;
        scanf("%d", &a);
        arr2[a-1]=1;
    }

    for(int i=0;i<N;i++)
    {
        if(arr1[i]==1||arr2[i]==1)
            uni[i]=1;
        if(arr1[i]==1&&arr2[i]==1)
            inter[i]=1;
    }
     printf("the union set is:\n");
    for(int i=0;i<N;i++)
        printf("%d ", uni[i] );
    printf("the intersection set is:\n");
    for(int i=0;i<N;i++)
        printf("%d ", inter[i]);


    return 0;

}
