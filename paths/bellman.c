#include <stdio.h>
#include <stdlib.h>
#define ll long long int
#define infinity 100000
#define nil -1
#define s(x) scanf("%d",&x)
#define p(x) printf("%d",x)
int distances[100001], state[100001];
int adj[1001][1001];
void funx(int v, int e)
{
	int i, dummy, j, k;
	for(i=1;i<=v;i++)
	{
		distances[i]=infinity;
		state[i]=1;
	}
	distances[1]=0;
	for(i=0;i<v-1;i++)
	{
		for(j=1;j<=v;j++)
		{
			for(k=1;k<=v;k++)
			{
				if(adj[j][k] && distances[k]>distances[j] + adj[j][k])
					distances[k]=distances[j] + adj[j][k];
			}
		}
	}
}
int main()
{
	int v, e, i, j, x, y, r;
	s(v);s(e);
	for(i=0;i<e;i++)
	{
		s(x);s(y);s(r);
		adj[x][y]=r;
	}

	funx(v, e);
	for(i=1;i<=v;i++)
	{
		p(distances[i]);
	}
  return 0;
}
