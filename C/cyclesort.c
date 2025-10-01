#include <stdio.h>
#include <stdlib.h>

int cycleSort(int arr[], int n) {
    int writes = 0;
    
    for (int cycle_start = 0; cycle_start <= n - 2; cycle_start++) {
        int item = arr[cycle_start];
        
        int pos = cycle_start;
        for (int i = cycle_start + 1; i < n; i++) {
            if (arr[i] < item) {
                pos++;
            }
        }
        
        if (pos == cycle_start) {
            continue;
        }
        
        while (item == arr[pos]) {
            pos++;
        }
        
        if (pos != cycle_start) {
            int temp = item;
            item = arr[pos];
            arr[pos] = temp;
            writes++;
        }
        
        while (pos != cycle_start) {
            pos = cycle_start;
            
            for (int i = cycle_start + 1; i < n; i++) {
                if (arr[i] < item) {
                    pos++;
                }
            }
            
            while (item == arr[pos]) {
                pos++;
            }
            
            if (item != arr[pos]) {
                int temp = item;
                item = arr[pos];
                arr[pos] = temp;
                writes++;
            }
        }
    }
    
    return writes;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
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
    
    int writes = cycleSort(arr, n);
    
    printf("Sorted array: ");
    printArray(arr, n);
    
    printf("Number of writes: %d\n", writes);
    
    free(arr);
    return 0;
}