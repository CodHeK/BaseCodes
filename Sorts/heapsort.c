#include<stdio.h>
int heapify(int* a, int i, int n)
{
	int j=(2*i+1),k=(2*i+2),x;
	if(j<=n)
	{
		if(k<=n)
			if(a[k]>a[j])
				j=k;
		if(a[j]>a[i])
		{
			x=a[j];
			a[j]=a[i];
			a[i]=x;
			heapify(a,j,n);
		}
	}
	return 0;
}
int buildheap(int *a, int n)
{
	int i;
	for(i=n/2;i>=0;i--)
		heapify(a,i,n-1);
	return 0;
}
int sort(int* a, int n)
{
	int x,i;
	buildheap(a,n);
	x=a[0];
	a[0]=a[n-1];
	a[n-1]=x;
	for(i=n-2;i>=0;i--)
	{
		heapify(a,0,i);
		x=a[0];
		a[0]=a[i];
		a[i]=x;
	}
	return 0;
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
    sort(a,n);
    end = clock();
	
    time = (float)(end - start);

	fprintf(fp,"%d	  %f\n",n,time);

	n += 100;
}
    return 0;
}
