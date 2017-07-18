#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int c;
    c = *b;
    *b = *a;
    *a = c;
}

void quickSort(int a[],int low, int high) 
{
    int pi;
    if(low < high) {
        
        pi  = partition(a,low,high);

        quickSort(a,low,pi-1);
        quickSort(a,pi+1,high);
    }
}

int partition(int a[], int low, int high)
{
    int pivot = a[high];
    int j;
    int i = (low - 1);

    for(j = low;j < high; j++) {
        
        if(a[j] <= pivot) {    
            i++;
            swap(&a[i],&a[j]);
        }
        
    }
    swap(&a[i+1],&a[high]);
    return (i+1);  //as now i+1 index wala element will become the last element which is the pivot
}

int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    int k;
    for(k=0;k<n;k++) {
        scanf("%d",&a[k]);
    }
    quickSort(a,0,n-1);
    for(k=0;k<n;k++) {
        printf("%d ",a[k]);
    }
    return 0;
}