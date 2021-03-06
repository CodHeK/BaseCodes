#include <stdio.h>
#include <stdlib.h>

void merge(int a[], int l, int m, int r) 
{
    int n1 = m - l + 1, n2 = r - m;
    int L[n1], R[n2];

    int i,j,k;

    for(i=0;i<n1;i++) {
        L[i] = a[l + i];
    }
    for(j=0;j<n2;j++) {
        R[j] = a[m + 1 + j];
    }

    i = 0,j = 0,k = l;
    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        }
        else {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    //checking if one is empty or not
    while(i < n1) {
        a[k] = L[i];    
        i++;
        k++;
    }

    while(j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int a[], int l, int r)
{
    if(l < r) {
    int m = (l+r)/2;
    
    mergeSort(a,l,m);
    mergeSort(a,m+1,r);

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