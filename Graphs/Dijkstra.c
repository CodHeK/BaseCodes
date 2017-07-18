#include <stdio.h>
#include <stdlib.h>
#define NIL -1
#define temp 0
#define infinity 9999
#define perm 1
void dij(int n, int v, int s, int adj[][n], int pred[], int status[], int pathlength[]);
int findmin(int n, int s, int v, int adj[][n], int pred[], int status[], int pathlength[]);
void create_graph(int n, int adj[][n]);

int main()
{
    int n, i;
    printf("Enter the number of edges:  ");
    scanf("%d", &n);
    int adj[n][n];
    int pred[n];
    int pathlength[n];
    int status[n];
    for(i=0; i<n; i++)
    {
        pred[i]=NIL;
        status[i]=temp;
        pathlength[i]=infinity;
    }
    create_graph(n, adj);
    int s;
    printf("Enter the source vertex: ");
    scanf("%d", &s);
    printf("Enter the destination vertex: ");
    int v;
    scanf("%d", &v);
    dij(n, v, s, adj, pred, status, pathlength);
}
void create_graph(int n, int adj[][n])
{
    int j, i, origin, dest, max_edges;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            adj[i][j]=0;    
        }
    }
    max_edges = n*(n-1);
    for(i=0; i<max_edges; i++)
    {
        printf("Enter the edge or -1 -1 to exit ");
        scanf("%d %d", &origin, &dest);
        if(origin==-1 && dest==-1)
            break;
        else if(origin<0 || dest<0 || origin>=n || dest>=n)
        {
            printf("Invalid Input\n");
            i--;
        }
        else
        {
            int wt;
            printf("Enter the weight: ");
            scanf("%d",&wt);
            adj[origin][dest]=wt;
        }
    }

    return;
}

void dij(int n, int v, int s, int adj[][n], int pred[], int status[], int pathlength[])
{
    int current, i;
    pathlength[s]=0;
    while(1)
    {
    current = findmin(n, s, v, adj, pred, status, pathlength );
    status[current]=perm;
    if(current==-1)
        return;
    for(i=0; i<n; i++)
    {
        if(adj[current][i] != 0 && status[i]==temp)
        {
            if(pathlength[current] + adj[current][i] < pathlength[i])
            {
                pred[i]=current;
                pathlength[i] = pathlength[current] + adj[current][i];
            }
        }
    }
    printf("Path length id %d", pathlength[v]);
    }
    return;
}

int findmin(int n, int s, int v, int adj[][n], int pred[], int status[], int pathlength[])
{
    int min = infinity;
    int k=-1;
    int i;
    for(i=0; i<n; i++)
    {
        if(status[i]==temp && pathlength[i]<min)
        {
            min = pathlength[i];
            k = i;
        }
    }
    printf("\n %d k\n", k);
    return k;
}