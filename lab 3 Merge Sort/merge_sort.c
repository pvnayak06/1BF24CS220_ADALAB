#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int low, int mid, int high) {
    int i = low, j = mid + 1, k = 0;
    int temp[100];

    while (i <= mid && j <= high) {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= high)
        temp[k++] = arr[j++];

    for (i = low, k = 0; i <= high; i++, k++)
        arr[i] = temp[k];
}

void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

void main() {
    int n, i;
    int arr[100000];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("\nEnter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    clock_t start, end;

    start = clock();
    mergeSort(arr, 0, n - 1);
    end = clock();

    double time_taken = ((double)(end - start) / CLOCKS_PER_SEC) * 1000;

    printf("\nSorted array:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\nTime Taken = %f ms\n", time_taken);

}
