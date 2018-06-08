#include<stdio.h>
#define s(n) scanf("%d",&n)
int siz;
int arr[100009];
void heapify(int arr[],int i,int siz)
{
	int l=2*i+1;
	int r=2*i+2;
	int largest;
	if(l<siz && arr[l]>arr[i])
        largest=l;
    else
        largest=i;
    if(r<siz && arr[r]>arr[largest])
    	largest=r;
    if(largest != i)
    {
        int temp=arr[i];
       	arr[i]=arr[largest];
       	arr[largest]=temp;
        heapify(arr,largest,siz);
    } 
}
int extractmax()
{
	int x=arr[0];
	int temp=arr[0];
	arr[0]=arr[siz-1];
	siz--;
	for(int i=0;i<=siz/2;i++)
		heapify(arr,i,siz);
	return x;
}
void insert(int val)
{
	arr[siz]=val;
	siz++;
	int i=siz-1;

	while(i>=0 && arr[(i-1)/2]<arr[i])
	{
		int temp=arr[(i-1)/2];
		arr[(i-1)/2]=arr[i];
		arr[i]=temp;
		i=(i-1)/2;
	}
}
int main()
{
	int n;
	s(n);
	siz=0;
	// DEFINE PRIORITY QUEUE
	for(int i=0;i<n;i++)
	{
		int x;
		s(x);
		insert(x);
	}
	int q;
	s(q);
	while(q--)
	{
		int x;
		s(x);
		if(x==1)
		{
			int val;
			s(val);
			int i;
			insert(val);
		}
		else
		{
			printf("%d\n",extractmax());
		}
	}
}