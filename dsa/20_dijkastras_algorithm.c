#include <stdio.h>

#define MAX 100
#define INF 99999

int graph[MAX][MAX], dist[MAX], visited[MAX], n;

int find_min_vertex() {
  int min_index = -1, min_value = INF;
  for (int i = 0; i < n; i++) {
    if (!visited[i] && dist[i] < min_value) {
      min_value = dist[i];
      min_index = i;
    }
  }
  return min_index;
}

void dijkstra(int src) {
  for (int i = 0; i < n; i++) {
    dist[i] = INF;
    visited[i] = 0;
  }
  dist[src] = 0;

  for (int i = 0; i < n - 1; i++) {
    int u = find_min_vertex();
    if (u == -1) break;
    visited[u] = 1;
    for (int v = 0; v < n; v++) {
      if (graph[u][v] && !visited[v] && dist[u] + graph[u][v] < dist[v]) {
        dist[v] = dist[u] + graph[u][v];
      }
    }
  }

  printf("Vertex   Distance from Source %d\n", src);
  for (int i = 0; i < n; i++) printf("%d        %d\n", i, dist[i]);
}

int main() {
  printf("Enter number of vertices: ");
  scanf("%d", &n);
  printf("Enter adjacency matrix (0 for no connection):\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &graph[i][j]);
      if (graph[i][j] == 0 && i != j) graph[i][j] = INF;
    }
  }
  int src;
  printf("Enter source vertex: ");
  scanf("%d", &src);
  dijkstra(src);
  printf("\n-------------------\n");
  printf("Programmed By Rabin Acharya.\n");
  return 0;
}

