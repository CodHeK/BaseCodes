#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
int partition(int arr[], int lb, int ub)
{
	int i = lb-1,j;
	int pivot= arr[ub];
	for(j=lb;j<=ub-1;j++)
	{
		if(arr[j]<=pivot)
		{
			++i;
			swap(&arr[j],&arr[i]);
		}
	}
	swap(&arr[i+1],&arr[ub]);
	return (i+1);
}
int randomn(int arr[], int lb, int ub)
{
	int r = rand()%(ub-lb+1);
	swap(&arr[lb+r],&arr[ub]);
	return partition(arr,lb,ub);
}
void quickSort(int arr[], int lb, int ub)
{
	if(lb<ub)
	{
		int pi = randomn(arr, lb, ub);
		quickSort(arr,lb,pi-1);
		quickSort(arr,pi+1,ub);
	}
}
int main()
{
	int n,i;
	scanf("%d",&n);
	int arr[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	quickSort(arr, 0, n-1);
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
}