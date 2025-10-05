
// Author: tanshen-kun
// Hacktoberfest2025

#include <stdio.h>

void removeDup(int arr[], int *size) {

  for (int i = 0; i < *size - 1; i++) {
    for (int j = i + 1; j < *size; j++) {
      if (arr[i] == arr[j]) { // duplicate found
        for (int k = j; k < *size - 1; k++) {
          arr[k] = arr[k + 1]; // shift the array
        }
        (*size)--; // reduce size
        j--;       // reduce index
      }
    }
  }
}
void printArr(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main() {
  int arr[] = {1, 2, 3, 4, 1, 2, 3, 4};
  int size = sizeof(arr) / sizeof(arr[0]);

  printf("Array Before :\n");
  printArr(arr, size);

  removeDup(arr, &size);

  printf("Array After :\n");
  printArr(arr, size);

  return 0;
}
