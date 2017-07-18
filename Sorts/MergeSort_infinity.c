//mergeSort using infinty Element
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void merge(int a[], int l, int m, int r)
{
    int L[m - l + 2], R[r - m + 1],i,j = 0, k = 0;
    for(i=l;i<=m;i++) {
        L[j] = a[i];
        ++j;
    }
    L[j] = INT_MAX;    

    j = 0;
    for(i=m+1;i<=r;i++) {
        R[j] = a[i];
        ++j;
    }
    R[j] = INT_MAX;

    i = 0;j = 0;
    for(k=l;k<=r;k++) {
        if(L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        }
        else {
            a[k] = R[j];
            j++;
        }
    }    
}

void mergeSort(int a[], int l, int r)
{
    int m = (l+r)/2;
    if(l < r) {
        mergeSort(a,l,m);
        mergeSort(a,m+1,r);
        //printf("%d %d %d\n",l ,m ,r);
        merge(a,l,m,r);
    }
}

int main()
{
    int n,i;
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++) {
        scanf("%d",&arr[i]);
    }
    mergeSort(arr,0,n-1);
    for(i=0;i<n;i++) {
        printf("%d ",arr[i]);
    }
    return 0;
}