#include <stdio.h>

#define MAX 100

int adj[MAX][MAX], visited[MAX], queue[MAX], front = 0, rear = 0, n;

void dfs(int v) {
  printf("%d ", v);
  visited[v] = 1;
  for (int i = 0; i < n; i++) {
    if (adj[v][i] && !visited[i]) {
      dfs(i);
    }
  }
}

void bfs(int v) {
  front = rear = 0;
  queue[rear++] = v;
  visited[v] = 1;
  
  while (front < rear) {
    int node = queue[front++];
    printf("%d ", node);
    for (int i = 0; i < n; i++) {
      if (adj[node][i] && !visited[i]) {
        queue[rear++] = i;
        visited[i] = 1;
      }
    }
  }
}

void reset_visited() {
  for (int i = 0; i < n; i++) visited[i] = 0;
}

int main() {
  int choice, start;
  
  printf("Enter number of vertices: ");
  scanf("%d", &n);
  
  printf("Enter adjacency matrix:\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &adj[i][j]);
    }
  }
  printf("\n*********Tree Traversal Techniques*********\n");
  while (choice != 3) {
    printf("Choose what you want to do: ");
    printf("\n1. DFS\n2. BFS\n3. Exit\nEnter choice: ");
    scanf("%d", &choice);
        
    reset_visited();
    
    switch (choice) {
      case 1:
        printf("Enter starting vertex: ");
        scanf("%d", &start);
        printf("DFS: ");
        dfs(start);
        break;
      case 2:
        printf("Enter starting vertex: ");
        scanf("%d", &start);
        printf("BFS: ");
        bfs(start);
        break;
      case 3:
        printf("Exiting.....");
        break;
      default:
        printf("Invalid choice.\n");
    }
    printf("\n");
  }
  printf("\n----------------------\n");
  printf("Programmed By Rabin Acharya.\n");
  return 0;
}

