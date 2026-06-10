#include <stdio.h>
#include <time.h>

#define INF 999

int minKey(int key[], int mstSet[], int V) {
    int min = INF, min_index;

    for (int v = 0; v < V; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void primMST(int V, int graph[][V]) {
    int parent[V];
    int key[V];
    int mstSet[V];

    for (int i = 0; i < V; i++) {
        key[i] = INF;
        mstSet[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet, V);
        mstSet[u] = 1;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printf("\nEdge \tWeight\n");
    int total = 0;
    for (int i = 1; i < V; i++) {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
        total += graph[i][parent[i]];
    }
    printf("Total cost of MST = %d\n", total);
}

void main() {
    int V;
    clock_t start, end;
    double time_taken;

    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    int graph[V][V];
    printf("\nEnter the adjacency matrix:\n");
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    start = clock();
    primMST(V, graph);
    end = clock();


    time_taken = (((double) (end - start)) / CLOCKS_PER_SEC) * 1000;
    printf("\n\nTime Taken: %f ms\n");
}
