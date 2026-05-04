#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int PARTITION(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void QUICKSORT(int arr[], int low, int high) {
    if (low < high) {
        int p = PARTITION(arr, low, high);
        QUICKSORT(arr, low, p - 1);
        QUICKSORT(arr, p + 1, high);
    }
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    srand(time(0));
    clock_t start, end;

    printf("Generated Array:\n");
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
        printf("%d ", arr[i]);
    }

    start = clock();
    QUICKSORT(arr, 0, n - 1);
    end = clock();

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nSorted Array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nTime taken for quicksort: %f seconds\n", time_taken);

    return 0;
}
