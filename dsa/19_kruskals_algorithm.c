#include <stdio.h>

#define MAX 100

typedef struct {
  int u, v, w;
} Edge;

Edge edges[MAX];
int parent[MAX], n, e;

int find(int x) {
  while (parent[x] != x) 
    x = parent[x];
  return x;
}

void union_sets(int a, int b) {
  parent[find(b)] = find(a);
}

void sort_edges() {
  for (int i = 0; i < e - 1; i++) {
    for (int j = 0; j < e - i - 1; j++) {
      if (edges[j].w > edges[j + 1].w) {
        Edge temp = edges[j];
        edges[j] = edges[j + 1];
        edges[j + 1] = temp;
      }
    }
  }
}

void kruskal() {
  int cost = 0, count = 0;
  sort_edges();
  for (int i = 0; i < n; i++) parent[i] = i;
  printf("Edges in MST:\n");
  for (int i = 0; i < e; i++) {
    if (find(edges[i].u) != find(edges[i].v)) {
      union_sets(edges[i].u, edges[i].v);
      printf("%d - %d | Weight: %d\n", edges[i].u, edges[i].v, edges[i].w);
      cost += edges[i].w;
      count++;
      if (count == n - 1) break;
    }
  }
  printf("Total MST Cost: %d\n", cost);
}

int main() {
  printf("Enter number of vertices and edges: ");
  scanf("%d %d", &n, &e);
  printf("Enter edges (u v w):\n");
  for (int i = 0; i < e; i++)
    scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
  kruskal();
  printf("\n-----------------\n");
  printf("Programmed By Rabin Acharya.\n");
  return 0;
}

