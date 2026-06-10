#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int x[20], n;

int placeQueen(int k, int i)
{
    for(int j = 1; j <= k - 1; j++)
    {
        if((x[j] == i) || (abs(j - k) == abs(x[j] - i)))
            return 0;
    }

    return 1;
}

void printSolution()
{
    int i, j;

    printf("\nSolution:\n");

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            if(x[i] == j)
                printf(" Q ");
            else
                printf(" . ");
        }
        printf("\n");
    }
}

void nQueens(int n)
{
    int k = 1;

    x[k] = 0;

    while(k != 0)
    {
        x[k] = x[k] + 1;

        while((x[k] <= n) && !placeQueen(k, x[k]))
            x[k]++;

        if(x[k] <= n)
        {
            if(k == n)
            {
                printSolution();
                return;
            }
            else
            {
                k++;
                x[k] = 0;
            }
        }
        else
        {
            k--;
        }
    }

    printf("No Solution Exists\n");
}

void main()
{
    clock_t start, end;

    printf("Enter number of queens: ");
    scanf("%d", &n);

    start = clock();
    nQueens(n);
    end = clock();

    double time_taken = (((double)(end - start)) / CLOCKS_PER_SEC) * 1000;
    printf("\n\nTime Taken: %f ms\n", time_taken);
}
