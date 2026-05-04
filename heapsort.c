#include <stdio.h>
#define MAX 50

void heapify(int a[MAX], int n, int i) {
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && a[left] > a[largest])
        largest = left;

    if (right <= n && a[right] > a[largest])
        largest = right;

    if (largest != i) {
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        heapify(a, n, largest);
    }
}

void heapsort(int a[MAX], int n) {

    for (int i = n / 2; i >= 1; i--)
        heapify(a, n, i);


    for (int i = n; i >= 2; i--) {
        int temp = a[1];
        a[1] = a[i];
        a[i] = temp;
        heapify(a, i - 1, 1);
    }
}

int main() {
    int n, a[MAX];
    printf("Enter the value of n: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    heapsort(a, n);

    printf("Array after performing heapsort:\n");
    for (int i = 1; i <= n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
