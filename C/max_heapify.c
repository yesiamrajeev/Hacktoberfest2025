#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void max_heapify(int arr[], int n, int i) {
    int largest = i;        
    int left = 2 * i + 1;   // left child 
    int right = 2 * i + 2;  // right child

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);

        // Recursively heapify 
        max_heapify(arr, n, largest);
    }
}
int main() {
    int arr[] = {3, 9, 2, 1, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = n / 2 - 1; i >= 0; i--) {
        max_heapify(arr, n, i);
    }

    printf("Max Heap: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
