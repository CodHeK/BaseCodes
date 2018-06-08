#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int findMin(int dist[], int visited[], int V) {
    int minIndex, minVal = INT_MAX;

    for (int i = 0; i < V; i++) {
        if (visited[i] == 0 && dist[i] <= minVal) {
            minVal = dist[i];
            minIndex = i;
        }
    }

    return minIndex;
}

void printSol(int dist[], int V) {
    for (int i = 0; i < V; i++) {
        if (dist[i] != INT_MAX) {
            printf("%d   %d\n", i, dist[i]);
        }
    }
}

int dij(int graph[1000][1000], int V, int src) {
    int visited[1000] = {0};
    int dist[1000], u;

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
    }

    dist[src] = 0;

    for (int i = 0; i < V; i++) {
        u = findMin(dist, visited, V);
        visited[u] = 1;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] != 0 && visited[v] == 0 && (dist[u] + graph[u][v] < dist[v])) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printSol(dist, V);
}

int main() {
    int V;
    scanf("%d", &V);
    int no_of_edges, u, v, w, src;
    scanf("%d", &no_of_edges);
    int graph[1000][1000] = {0};
    int reverseGraph[1000][1000] = {0};

    while (no_of_edges--) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
    }

    // for (int i = 0; i < V; i++) {
    //     for (int j = 0; j < V; j++) {
    //         reverseGraph[i][j] = graph[j][i];
    //     }
    // }

    scanf("%d", &src);

    dij(graph, V, src);

    return 0;
}
