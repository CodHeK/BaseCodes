#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
	int c;
	c = *b;
	*b = *a;
	*a = c;
}

void heapify(int a[], int n, int i)
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
		
		heapify(a,n,largest);
	}
}

void heapSort(int a[], int n)
{
	int i;
	for(i=n/2 - 1;i>=0;i--) {
		heapify(a,n,i);
	}

	for(i=n-1;i>=0;i--) {
		swap(&a[0], &a[i]);
		heapify(a,i,0);
	}
}
int main()
{
    clock_t start;
    clock_t end;

    float time;
   
    FILE* fp = NULL;
    fp = fopen("heap.txt","w+");


    int n=100,i;
    while(n<=1000000) {
    int a[n];
    for(i=0;i<n;i++)
        a[i] = rand()%10000000;
    start = clock();
    heapSort(a,n-1);
    end = clock();
   
    time = (float)(end - start);

    fprintf(fp,"%d      %f\n",n,time);

    n += 100;
}
    return 0;
}	
		

