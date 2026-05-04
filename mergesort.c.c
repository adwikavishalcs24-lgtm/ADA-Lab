#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void MERGE(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void MERGESORT(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        MERGESORT(arr, left, mid);
        MERGESORT(arr, mid + 1, right);
        MERGE(arr, left, mid, right);
    }
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    srand(time(0));
    clock_t start,end;

    printf("Generated Array:\n");
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
        printf("%d ", arr[i]);
    }
    start=clock();
    MERGESORT(arr, 0, n - 1);
    end=clock();

    double time_taken=(double)(end-start)/CLOCKS_PER_SEC;

    printf("\nSorted Array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n Time taken for merge sort : %f second \n",time_taken);

    return 0;
}
