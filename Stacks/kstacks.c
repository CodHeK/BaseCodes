#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void push(int arr[], int k, int data, int t[])
{
	arr[++t[k-1]]=data;
}
int pop(int arr[], int k, int t[])
{
	return arr[t[k-1]--];
}

int main()
{
	int k,i;
	int array[1000]={0};
	scanf("%d",&k);
	int top[k];
	for(i=0;i<k;i++)
	{
		top[i]=(1000/k)*(i)-1;
	}
	push(array, 2, 5, top);
	push(array, 3, 7, top);
	push(array, 4, 1, top);
	push(array, 2, 8, top);
	push(array, 2, 77, top);
	printf("%d\n",pop(array, 2, top));
	printf("%d\n",pop(array, 2, top));
	push(array, 2, 23, top);
	printf("%d\n",pop(array, 2, top));
	push(array, 3, 78, top);
	printf("%d\n",pop(array, 3, top));
	push(array, 1, 45, top);
	printf("%d\n",pop(array, 1, top));
	return 0;
}