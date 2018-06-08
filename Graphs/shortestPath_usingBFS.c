#include <stdio.h>
#include <stdlib.h>
#define MAX  100
#define infinity 100000
int rear =-1, front = -1;
void push(int queue[], int x)
{
    if(rear == MAX-1)
        printf("Queue Overflow");
    else
    {
        if(front == -1)
            front =0;
        rear = rear+1;
        queue[rear]=x;
    }
}

int pop(int queue[])
{
    int del;
    if(front==-1 || front> rear)
    {
        printf("Queue Underflow");
        exit(1);
    }
    del = queue[front];
    front = front+1;
    return del;
}

int IsEmpty(int queue[])
{
    if(front==-1 || front>rear)
        return 1;
    else return 0;
}

int main()
{   
    int distance[MAX];
    int pred[MAX]; 
    int initial = 1;
    int waiting = 2;
    int visited = 3;
    int n, i, j, origin, dest, max_edges, x, y;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    int adj[n][n];
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            adj[i][j]=0;
        }
    }

    max_edges = (n)*(n-1);
    for(i=1; i<=max_edges; i++)
    {
        printf("Enter the edges or -1 -1 to exit ");
        scanf("%d %d", &origin, &dest);
        if(origin==-1 && dest==-1)
            break;
        else if(origin<0 || dest<0 || origin>=n || dest>=n)
            {
                printf("Invalid Input");
                i--;
            }
        else adj[origin][dest]=1;   
    }

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("%d  ", adj[i][j]);
        }
        printf("\n");
    }  
 
    printf("Enter the start vertex for BFS: ");
    scanf("%d", &x);
    int state[n];
    int queue[MAX];
    for(i=0; i<n; i++)
    {
        state[i] = initial;
    pred[i] = -1;
    distance[i] = infinity;
    }
    for(i=0; i<MAX; i++)
        queue[i]=0;
    push(queue, x);
    state[x]=waiting;
    distance[x] = 0;
    while(!IsEmpty(queue))
    {
        y = pop(queue);
        //printf("%d  ", y);
        state[y]=visited;
        for(i=0; i<n; i++)
        {
            if(adj[y][i]==1 && state[i]==initial)
            {
                push(queue, i);
                state[i]=waiting;
        pred[i] = y;
        distance[i] = distance[y] + 1;
            }
        }
    }
    int path[MAX],count = 0, u;
    int dv;
    printf("Enter dest vertex\n");
    scanf("%d",&dv);
    printf("%d \n",distance[dv]);
    printf("Path : \n");
    while(dv != -1) {
        count++;
        path[count] = dv;
        u = pred[dv];
        dv = u;
    }
    for(i=count;i>1;i--) {
        printf("%d-> ",path[i]);
    }
    return 0;
}