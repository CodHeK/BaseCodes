#include <stdio.h>
#include <stdlib.h>
#define s(x) scanf("%d",&x)
#define p(x) printf("%d",x)
#define N 1005
int arr[4*N],a[N],n;
void swap(int *x, int *y)
{
	int t=*x;
	*x=*y;
	*y=t;
	return;
}
void max_heapify(int arr[], int i, int siz)
{
	int l=2*i,r=2*i+1,largest=i;
	if(l<=siz && arr[l]>arr[i])
		largest=l;
	if(r<=siz && arr[r]>=arr[largest])
		largest=r;
	if(largest!=i)
	{
		swap(&arr[i],&arr[largest]);
		max_heapify(arr,largest,siz);
	}
}
void build_heap(int arr[], int siz)
{
	int i;
	for(i=siz/2;i>=1;i--)
		max_heapify(arr,i,siz);
}
int maxer(int arr[])
{
	return arr[1];
}
int extract_max(int arr[], int *siz)
{
	int ans=arr[1];
	swap(&arr[1],&arr[*siz]);
	*siz=*siz-1;
	max_heapify(arr,1,*siz);
	return ans;
}
void heap_sort(int arr[], int siz)
{
	int i;
	for(i=siz;i>=2;i--)
	{
		swap(&arr[1],&arr[i]);
		max_heapify(arr,1,i-1);
	}
}
void inc_val(int arr[], int i, int val)
{
	arr[i]=val;
	while(i>1 && arr[i/2]<arr[i])
	{
		swap(&arr[i],&arr[i/2]);
		i=i/2;
	}
}
void disp(int arr[], int siz)
{
	int i;
	for(i=1;i<=siz;i++)
	{
		p(arr[i]);
		printf(" ");
	}
}
void insert(int x, int *siz)
{
	*siz=*siz+1;
	arr[*siz]=-1;
	inc_val(arr,*siz,x);
}
int main()
{
	int i,j,k;
	s(n);
	for(i=1;i<=n;i++)
		s(arr[i]);
	build_heap(arr,n);
	disp(arr,n);
	printf("\n");
	insert(7,&n);
	disp(arr,n);
	//p(maxer(arr));
	//printf("\n");
	//heap_sort(arr,n);
	//for(i=1;i<=n;i++)
	//	p(arr[i]);printf(" ");
	//p(extract_max(arr,&n));printf("\n");
	//p(n);
}