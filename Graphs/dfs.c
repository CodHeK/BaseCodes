#include <stdio.h>
#include <stdlib.h>

#define initial 1
#define visited 2


int push(int stack[], int top, int data)
{
    top = top + 1;
    stack[top] = data;
    return top;
}

int pop(int stack[], int top)
{
    top = top - 1;
    return top;
}

int front(int stack[], int top)
{
    return stack[top];
}

int emptyStack(int stack[], int top)
{
    if(top == -1)
        return 1;
    else 
        return 0;
}


void createGraph(int n, int adj[][n])
{
    int j, origin, dest;
    int max_edge = n*(n-1);
    
    int i;
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {    
            adj[i][j] = 0;
        }
    }

    for(j=1;j<=max_edge;j++) {
        scanf("%d %d",&origin, &dest);    
        if(origin == -1 && dest == -1) 
            break;
        else if(origin >= n || dest >= n || origin < 0 || dest < 0) 
            j--;
        else 
            adj[origin][dest] = 1;
    }
}

void DFS(int v, int n, int state[], int adj[][n])
{
    int i,j;
    int stack[n]; 
    int top = -1;
    top = push(stack, top, v);
    for(i=0; i<n; i++)
        stack[i]=0;
    //printf("lol1\n");
    while(!emptyStack(stack, top)) {
        int y = front(stack, top);
        top = pop(stack,top);
        if(state[y]==initial) {
            state[y]=visited;
            printf("%d ",y);    
        }
        //printf("lol2\n");
        for(i=0;i<n;i++) {
            if(state[i] == initial && adj[y][i] == 1) {
                top = push(stack,top,i);
                //printf("lol3\n");
            }
        }
    }
}

void dfs_trav(int n, int adj[][n])
{
    int v;
    int state[n];
    for(v=0;v<n;v++) {
        state[v] = initial;
    }
    
    scanf("%d",&v);
    DFS(v,n,state,adj);
}
int main()
{
    int n;
    scanf("%d",&n);
    int adj[n][n];
    createGraph(n,adj);
    dfs_trav(n,adj);
    return 0;
}