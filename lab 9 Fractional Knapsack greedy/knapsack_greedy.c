#include <stdio.h>
#include <time.h>

float knapsack_greedy(int p[], int w[], int m, int n) {
    float x[n], max_profit = 0.0;
    for (int i = 0; i < n; i++) {
        x[i] = 0.0;
    }

    int rem_cap = m, i = 0;
    while (rem_cap > 0) {
        if (w[i] > rem_cap) break;
        x[i] = 1.0;
        rem_cap = rem_cap - w[i];
        i++;
    }

    if (rem_cap != 0 && i < n) {
        x[i] = (float)rem_cap / w[i];
    }

    for (int i = 0; i < n; i++) {
        max_profit = max_profit + (x[i] * p[i]);
    }

    return max_profit;
}

void main() {
    int n, m;
    clock_t start, end;
    double time_taken;

    printf("Enter number of objects: ");
    scanf("%d", &n);
    printf("Enter max capacity of Knapsack: ");
    scanf("%d", &m);

    int p[n], w[n];
    float wp[n], profit;

    printf("\nEnter profit, weight for %d objects\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &p[i], &w[i]);
        wp[i] = (float)p[i] / w[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (wp[i] < wp[j]) {

                float temp = wp[i];
                wp[i] = wp[j];
                wp[j] = temp;

                int temp2 = w[i];
                w[i] = w[j];
                w[j] = temp2;

                int temp3 = p[i];
                p[i] = p[j];
                p[j] = temp3;
            }
        }
    }

    start = clock();
    profit = knapsack_greedy(p, w, m, n);
    end = clock();

    printf("\nMaximum profit: %f", profit);

    time_taken = (((double) (end - start)) / CLOCKS_PER_SEC) * 1000;
    printf("\n\nTime Taken: %f ms\n", time_taken);
}
