#include<stdio.h>
#define s(n) scanf("%d",&n)
struct edje
{	
	int x,y,w;
};
struct edje arr[100005];
struct edje left[100004];
struct edje right[100004];
void merge(struct edje arr[],int l,int mid,int r)
{
	int n1=mid-l+1;
	int n2=r-mid;
	int i,j,k;
	for(i=0;i<n1;i++)
	{
		left[i].x=arr[l+i].x;
		left[i].y=arr[l+i].y;
		left[i].w=arr[l+i].w;
	}
	for(j=0;j<n2;j++)
	{
		right[j].x=arr[mid+1+j].x;
		right[j].y=arr[mid+1+j].y;
		right[j].w=arr[mid+1+j].w;
	}
	i=0;
	j=0;
	k=l;
	while(i<n1 && j<n2)
	{
		if(left[i].w<=right[j].w)
		{
			arr[k].x=left[i].x;
			arr[k].y=left[i].y;
			arr[k].w=left[i].w;
			i++;
		}
		else
		{
			arr[k].x=right[j].x;
			arr[k].y=right[j].y;
			arr[k].w=right[j].w;
			j++;	
		}
		k++;
	}
	while(i<n1)
	{
		arr[k].x=left[i].x;
		arr[k].y=left[i].y;
		arr[k].w=left[i].w;
		i++;
		k++;		
	}
	while(j<n2)
	{
		arr[k].x=right[j].x;
		arr[k].y=right[j].y;
		arr[k].w=right[j].w;
		j++;
		k++;	
	}
}
void mergesort(struct edje arr[],int l,int r)
{
	if(l<r)
	{
		int mid=l+(r-l)/2;
		mergesort(arr,l,mid);
		mergesort(arr,mid+1,r);
		merge(arr,l,mid,r);
	}
}
int id[100000];
void initialize(int n)
{
	for(int i=0;i<=n;i++)
		id[i]=i;
}
int root(int x)
{
	while(id[x]!=x)
	{
		id[x]=id[id[x]];
		x=id[x];
	}
	return x;
}
void unin(int x,int y)
{
	int p=root(x);
	int q=root(y);
	id[p]=id[q];
}
int kruskal(int m)
{
	int x,y,i,mincost=0,cost;
	for(i=0;i<m;i++)
	{
		x=arr[i].x;
		y=arr[i].y;
		cost=arr[i].w;
		if(root(x)!=root(y))
		{
			mincost=mincost+cost;
			unin(x,y);
		}
	}
	return mincost;
}
int main()
{
	int n,m;
	s(n);
	s(m);
	int x,y,w;
	int i;
	initialize(n);
	for(i=0;i<m;i++)
	{
		s(x);
		s(y);
		s(w);
		arr[i].x=x;
		arr[i].y=y;
		arr[i].w=w;
	}
	mergesort(arr,0,m-1);
	printf("%d",kruskal(m));	
}