#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define s(x) scanf("%d",&x)
#define p(x) printf("%d ",x)

int graph[1001][1001], visited[1001], V;

void dfs(int v) {
  int i;
  visited[v] = 1;
  for(i=0;i<V;i++) {
    if(graph[v][i] == 1 && visited[i] == 0) {
      dfs(i);
    }
  }
}

int main()
{
  int e, i;
  s(V); s(e);
  for(i=0;i<V;i++) {
    visited[i] = 0;
  }
  while(e--) {
    int x, y;
    s(x); s(y);
    graph[x][y] = 1;
    graph[y][x] = 1;
  }
  int comps = 0;
  comps++;
  dfs(0);
  for(i=0;i<V;i++) {
    if(visited[i] == 0) {
      comps++;
      dfs(i);
    }
  }
  p(comps);
  return 0;
}
