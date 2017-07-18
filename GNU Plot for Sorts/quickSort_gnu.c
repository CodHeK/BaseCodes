#include <stdio.h>
#include <stdlib.h>

void swap(int *a,int *b)
{
	int c;
	c = *b;
	*b = *a;
	*a = c;
}

void quickSort(int a[], int low, int high)
{
	int pi;
	if(low < high) {
		
		pi = partition(a,low,high);
		
		quickSort(a,low,pi-1);
		quickSort(a,pi+1,high);
	}
}

int partition(int a[], int low, int high)
{
	int pivot = a[high];

	int i = (low - 1), j;

	for(j = low;j < high; j++) {
		if(a[j] <= pivot) {
			i++;
			swap(&a[i],&a[j]);
		}
	}
	swap(&a[i+1],&a[high]);
	return (i+1);
}

int main()
{
    clock_t start;
    clock_t end;

    float time;
   
    FILE* fp = NULL;
    fp = fopen("quick.txt","w+");


    int n=100,i;
    while(n<=1000000) {
    int a[n];
    for(i=0;i<n;i++)
        a[i] = rand()%10000000;
    start = clock();
    quickSort(a,0,n-1);
    end = clock();
   
    time = (float)(end - start);

    fprintf(fp,"%d      %f\n",n,time);

    n += 100;
}
    return 0;
}

