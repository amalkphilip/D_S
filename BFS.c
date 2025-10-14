#include <stdio.h>

#define MAX 100

void bfs(int graph[MAX][MAX], int n, int start) {
    int queue[MAX];
    int front = 0, rear = 0;
    int visited[MAX] = {0};

    queue[rear++] = start;
    visited[start] = 1;

    printf("BFS traversal starting from node %d:\n", start);

    while (front < rear) {
        int current = queue[front++];  
        printf("%d ", current);

        for (int i = 0; i < n; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main() {
    int n, start;
    int graph[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter starting node (0 to %d): ", n - 1);
    scanf("%d", &start);

    bfs(graph, n, start);

    return 0;
}

