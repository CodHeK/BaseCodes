#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
int partition(int arr[], int l, int r)
{
	int pivot = arr[r];
	int i = l,j;
	for(j=l;j<=r-1;j++)
	{
		if(arr[j]<=pivot)
		{
			swap(&arr[i],&arr[j]);
			i++;
		}
	}
	swap(&arr[i],&arr[r]);
	return i;
}
int quickSelect(int array[], int l, int r, int k)
{
	if(k>0&&k<=r-l+1)
	{
		int pos = partition(array,l,r);
		if(pos-l==k-1)
			return array[pos];
		if(pos-l>k-1)
			return quickSelect(array,l,pos-1,k);
		return quickSelect(array,pos+1,r,k-pos+l-1);
	}
	return INT_MAX;
}
int main()
{
	int n;
	scanf("%d",&n);
	int i,k;
	int arr[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	scanf("%d",&k);
	//printf("%d\n",partition(arr,0,n-1) );
	printf("%d\n",quickSelect(arr,0,n-1,k));
	return 0;
}