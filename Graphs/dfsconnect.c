#include <stdio.h>
#include <stdlib.h>

#define initial 1
#define visited 2

#define MAX 10000

void push(int stack[], int x, int *top)
{
	*top = *top + 1;
	stack[*top] = x;
}

int pop(int stack[], int *top)
{	
	int item;
	item = stack[*top];
	*top = *top - 1;
	return item;
}

int emptyStack(int stack[], int *top)
{
	if(*top == -1) 
		return 1;
	else
		return 0;
}

void createGraph(int n, int adj[][n])
{
	int i,j, origin, dest, max_edge;	
	max_edge = n*(n-1);
	
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) {
			adj[i][j] = 0;
		}
	}

	for(j=1;j<=max_edge;j++) {
		scanf("%d %d",&origin, &dest);
		if(origin == -1 && dest == -1) 
			break;
		if(origin >= n || dest >= n || origin < 0 || dest < 0) 
			j--;
		else 
			adj[origin][dest] = 1;
		
	}
	/*for(i=1;i<=n;i++) {
		for(j=1;j<=n;j++) {
			scanf("%d",&adj[i][j]);
		}
		//printf("\n");
	}*/
}

void DFS(int v, int n, int adj[][n], int state[], int stack[], int *top, int compt)
{
	int i;
        push(stack,v,top);
        
	while(!emptyStack(stack,top)) {	
		int y = pop(stack,top);
		
			printf("%d ",y);
			state[y] = visited;
		
		for(i=0;i<n;i++) {
			if(state[i] == initial && adj[y][i] == 1) {
				push(stack,i,top);
			}
		}
	}
	printf("\n");
}


void dfs_trav(int n, int state[], int stack[], int adj[][n], int *top)
{
	int i,v;
	int compt = 0;
	for(i=0;i<n;i++) {
		state[i] = initial;
	}
	printf("Enter The Starting Vertex : \n");
	scanf("%d",&v);
	compt++;
	DFS(v,n,adj,state,stack,top,compt);

	for(i=0;i<n;i++) {
		if(state[i] == initial) {
			compt++;
			DFS(i,n,adj,state,stack,top,compt);
		}
	}
	printf("Total Number of Components = %d\n",compt);
}
int main()
{
	int n, i;
	scanf("%d",&n);
	int adj[n][n];
	int state[n];
	int top = -1;
	int stack[MAX];
	for(i=0;i<MAX;i++)	
		stack[i] = 0;
	createGraph(n,adj);
	dfs_trav(n,state,stack,adj,&top);
	return 0;
}
