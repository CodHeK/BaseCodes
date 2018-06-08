void dfs(int v) {
  print(v);
  visited[v] = 1;

  for(j=0;j<n;j++) {
    if(visited[j] == 0 && graph[v][j] == 1) {
      dfs(j);
    }
  }
}
