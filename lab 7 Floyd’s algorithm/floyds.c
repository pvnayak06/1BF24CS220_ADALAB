#include <stdio.h>
#include <time.h>
#define INF 999
void main() {
    int n, i, j, k;
    clock_t start, end;
    double time_taken;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    int dist[n][n];
    printf("\nEnter adjacency matrix: ");
    printf("(Use %d for INF)\n", INF);
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &dist[i][j]);
        }
    }
    start = clock();
    for(k = 0; k < n; k++) {
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {

                if(dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }

            }
        }
    }
    end = clock();
    printf("\nShortest Distance Matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {

            if(dist[i][j] == INF)
                printf("INF ");
            else
                printf("%d ", dist[i][j]);
        }
        printf("\n");
    }
    time_taken = (((double) (end - start)) / CLOCKS_PER_SEC) * 1000;
    printf("\n\nTime Taken: %f ms\n", time_taken);
}
