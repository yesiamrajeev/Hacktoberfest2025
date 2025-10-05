// Peak in a rotated array

// Minimum Element in a rotated sorted array

// Problem:

// A sorted array containing all unique elements is rotated some unknown number of times, find the minimum element in it.

// We can use binary search to solve this.
#include <iostream>
using namespace std;

int findMin(int arr[], int n) {

    int lo = 0, hi = n - 1;

    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (arr[mid] < arr[hi]) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }

    return arr[lo];
}

int main() {
    int arr[] = {4, 5, 6, 1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int minElement = findMin(arr, n);
    cout << "Minimum element in the rotated array is: " << minElement << endl;
    return 0;
}