#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define INF 999

struct Edge {
    int u, v, w;
};

struct Edge edges[MAX], result[MAX];
int parent[MAX];

int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void unionSet(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

void sortEdges(int E) {
    struct Edge temp;
    for (int i = 0; i < E - 1; i++) {
        for (int j = 0; j < E - i - 1; j++) {
            if (edges[j].w > edges[j + 1].w) {
                temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

void main() {
    int V;
    int cost[MAX][MAX];
    int E = 0;
    clock_t start, end;
    double time_taken;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("\nEnter cost matrix (use 0 or %d for no edge):\n", INF);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {
            if (cost[i][j] != 0 && cost[i][j] != INF) {
                edges[E].u = i;
                edges[E].v = j;
                edges[E].w = cost[i][j];
                E++;
            }
        }
    }


    for (int i = 0; i < V; i++)
        parent[i] = i;

    start = clock();
    sortEdges(E);
    end = clock();

    int i = 0, count = 0;
    int minCost = 0;

    while (count < V - 1 && i < E) {
        int u = edges[i].u;
        int v = edges[i].v;

        int setU = find(u);
        int setV = find(v);

        if (setU != setV) {
            result[count++] = edges[i];
            minCost += edges[i].w;
            unionSet(setU, setV);
        }
        i++;
    }

    printf("\nEdges in MST:\n");
    for (i = 0; i < count; i++) {
        printf("%d - %d : %d\n", result[i].u, result[i].v, result[i].w);
    }

    printf("Minimum cost = %d\n", minCost);

    time_taken = (((double) (end - start)) / CLOCKS_PER_SEC) * 1000;
    printf("\n\nTime Taken: %f ms\n", time_taken);
}
