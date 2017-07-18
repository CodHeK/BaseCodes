#include <stdio.h>
#include <stdlib.h>
#define MAX  100
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
{    int initial = 1;
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
    }
    for(i=0; i<MAX; i++)
        queue[i]=0;
    push(queue, x);
    state[x]=waiting;
    while(!IsEmpty(queue))
    {
        y = pop(queue);
        printf("%d  ", y);
        state[y]=visited;
        for(i=0; i<n; i++)
        {
            if(adj[y][i]==1 && state[i]==initial)
            {
                push(queue, i);
                state[i]=waiting;
            }
        }
    }
    return 0;
}