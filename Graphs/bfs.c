void bfs(int v) {
  insert(v);
  state[v] = waiting

  while(!not_empty()) {
    delete(v);
    print(v);
    state[v] = visited;

    for(j=0;j<n;j++) {
      if(state[j] == initial && graph[v][j] == 1) {
        insert(j);
        state[j] = waiting;
      }
    }
  }
}
