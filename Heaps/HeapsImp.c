#include <stdio.h>
#include <stdlib.h>

void swap(int*a, int *b)
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

void maxHeap(int a[], int n, int i)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if(l < n && a[l] > a[largest]) {
        largest = l;
    }
    if(r < n && a[r] > a[largest]) {
        largest = r;
    }

    if(largest != i) {
        swap(&a[i], &a[largest]);

        maxHeap(a,n,largest);
    }
}

void minHeap(int a[], int n, int i)
{
    int smallest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if(l < n && a[l] < a[smallest]) {
        smallest = l;
    }
    if(r < n && a[r] < a[smallest]) {
        smallest = r;
    }

    if(smallest != i) {
        swap(&a[i], &a[smallest]);

        minHeap(a,n,smallest);
    }
}

void delHeap(int a[], int del)
{
    int i, c = 0, index;
    for(i=0;i<n;i++) {
        if(a[i] == del) {
            c++;
            index = i;
        }
    }
    while(c > 0) {
       swap(a[index], a[0]);
       for(i=n-1;i>=0;i--) {
        del
       }
       del(Heap)
    }
   
}

void print(int a[], int n)
{
    int i;
    for(i=0;i<n;i++) {
        printf("%d ",a[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    scanf("%d",&n);
    int a[n], b[n];
    int j;
    for(j=0;j<n;j++) {
        scanf("%d",&a[j]);
        b[j] = a[j];
    }
   // swap(&a[1],&a[2]);
    //print(a,n);
    for(j=n/2-1;j>=0;j--) {
        maxHeap(a,n,j);
    }
    for(j=n/2-1;j>=0;j--) {
        minHeap(b,n,j);
    }
    print(a,n); //maxHeap
    print(b,n); //minHeap
    return 0;
}