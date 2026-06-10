#include <stdio.h>
#include <time.h>

int knapsack_dp(int n, int M, int W[], int P[]) {
    int table[n+1][M+1];

    for (int i = 0; i <= n; i++)
        table[i][0] = 0;

    for (int j = 0; j <= M; j++)
        table[0][j] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= M; j++) {
            if (j < W[i-1]) {
                table[i][j] = table[i-1][j];
            } else {
                int x = table[i-1][j];
                int y = P[i-1] + table[i-1][j - W[i-1]];
                table[i][j] = (x > y) ? x : y;
            }
        }
    }

    return table[n][M];
}

void main() {
    int n, M;
    printf("Enter number of objects and capacity: ");
    scanf("%d %d", &n, &M);

    int P[n], W[n];

    printf("\nEnter profit and weight:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &P[i], &W[i]);
    }

    clock_t start, end;
    start = clock();
    int profit = knapsack_dp(n, M, W, P);
    end = clock();

    double time_taken = (((double) (end - start) / CLOCKS_PER_SEC)) * 1000;
    printf("\nMax Profit: %d\n", profit);

    printf("\n\nTime Taken: %f ms\n", time_taken);
}
