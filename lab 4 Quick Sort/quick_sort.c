#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);

        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

void main() {
    int n, i;
    int arr[100000];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("\nEnter the elements: ");
    for (i = 0; i < n; i++) {
       scanf("%d", &arr[i]);
    }

    clock_t start, end;

    start = clock();
    quickSort(arr, 0, n - 1);
    end = clock();

    double time_taken = ((double)(end - start) / CLOCKS_PER_SEC) * 1000;

   printf("\nSorted array:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\nTime Taken = %f ms\n", time_taken);

}
