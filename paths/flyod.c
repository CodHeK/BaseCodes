#include <stdio.h>
#include <stdlib.h>
#define infinity 1000005
int adj[1005][1005], path[1005][1005];
int main()
{
	int n, i, j, k,m,w;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(i==j)
			{
				adj[i][i]=0;
				continue;
			}
			adj[i][j]=infinity;
			path[i][j]=n+1;
		}
	}
	for(i=1;i<=m;i++)
	{
		scanf("%d %d %d",&j,&k,&w);
		adj[j][k]=w;
		path[j][k]=j;
	}
	for(k=1;k<=n;k++)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(adj[i][j]>adj[i][k]+adj[k][j])
				{
					adj[i][j]=adj[i][k]+adj[k][j];
					path[i][j]=path[k][j];
				}
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			printf("%d ",adj[i][j]);
		printf("\n");
	}
}
