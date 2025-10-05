
// Author : tanshen-kun
// Hacktoberfest2025

#include <stdio.h>

int linearSearch(int arr[], int size, int key) {
  for (int i = 0; i < size; i++) {
    if (arr[i] == key) { // key found
      return i;
    }
  }
  // if not found
  return -1;
}

int main() {
  int arr[] = {1, 10, 12, 34, 42, 12, 55};
  int size =  sizeof(arr) / sizeof(arr[0]); // total array size / first element size = number of element
  int key = 34;

  int index = linearSearch(arr, size, key);
  if (index != -1) {
    printf("Element found at Index : %d\n", index);
  } else {
    printf("Element not found!\n");
  }
  return 0;
}
