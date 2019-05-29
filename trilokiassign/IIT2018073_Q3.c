#include <stdio.h>
#include <stdlib.h>

void maintainheap(int arr[],int i,  int n)
{
    int largest;
    int left=2*i;
    int right=2*i+1;
    if(left<=n && arr[left]>arr[i])
    largest= left;
    else
        largest=i;
        if(right<=n && arr[right]>arr[largest])
            largest=right;
    if(largest!=i)
    {
        int b=arr[i];
        arr[i]=arr[largest];
        arr[largest]=b;
        maintainheap(arr,largest,n);
    }
}
void buildheap(int arr[],int n)
{
    for(int i=n/2;i>=1;i--)
    {
        maintainheap(arr,i,n);
    }
}
void postorder(int arr[],int i, int n)
{
    if(i<=n && i>=1)
    {


    if(2*i<=n)
        postorder(arr,2*i,n);
    if((2*i+1)<=n)
        postorder(arr,2*i+1,n);
    printf("%d ", arr[i]);
    }
}
int main()
{
    struct node* root=NULL;
    int array[]={0, 19, 22, 13, 7, 24, 17, 11, 3, 39, 51 };
    buildheap(array,10);
    postorder(array,1,10);

    return 0;
}
