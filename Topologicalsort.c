#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void topologicalSort(int n, int adj[MAX][MAX]) {
    int indegree[MAX] = {0};
    int i, j, count = 0;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (adj[j][i] == 1) {
                indegree[i]++;
            }
        }
    }

    printf("Topological Order: ");

    while (count < n) {
        int found = 0;
        for (i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                printf("%d ", i);
                indegree[i] = -1;
                count++;
                found = 1;

                for (j = 0; j < n; j++) {
                    if (adj[i][j] == 1) {
                        indegree[j]--;
                    }
                }
            }
        }
        if (!found) {
            printf("\nGraph has a cycle. Topological sort not possible.\n");
            return;
        }
    }
    printf("\n");
}

int main() {
    int n, e;
    int adj[MAX][MAX] = {0};
    int u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < e; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    topologicalSort(n, adj);

    return 0;
}
