#include <stdio.h>
#include <stdlib.h>

int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void countSort(int arr[], int n, int exp) {
    int output[n];
    int count[10] = {0};
    
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }
    
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
    
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void radixSort(int arr[], int n) {
    int max = getMax(arr, n);
    
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countSort(arr, n, exp);
    }
}

void radixSortWithNegative(int arr[], int n) {
    int* positive = (int*)malloc(n * sizeof(int));
    int* negative = (int*)malloc(n * sizeof(int));
    int pos_count = 0, neg_count = 0;
    
    for (int i = 0; i < n; i++) {
        if (arr[i] >= 0) {
            positive[pos_count++] = arr[i];
        } else {
            negative[neg_count++] = -arr[i];
        }
    }
    
    if (pos_count > 0) {
        radixSort(positive, pos_count);
    }
    
    if (neg_count > 0) {
        radixSort(negative, neg_count);
    }
    
    int index = 0;
    
    for (int i = neg_count - 1; i >= 0; i--) {
        arr[index++] = -negative[i];
    }
    
    for (int i = 0; i < pos_count; i++) {
        arr[index++] = positive[i];
    }
    
    free(positive);
    free(negative);
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int hasNegative(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            return 1;
        }
    }
    return 0;
}
int main() {
    int n;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    int* arr = (int*)malloc(n * sizeof(int));
    
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Original array: ");
    printArray(arr, n);
    
    if (hasNegative(arr, n)) {
        radixSortWithNegative(arr, n);
    } else {
        radixSort(arr, n);
    }
    
    printf("Sorted array: ");
    printArray(arr, n);
    
    free(arr);
    return 0;
}