// Finding Peak in 1-D Array

// Given an array of distinct integers, print index of a peak element in it. An array element is a peak if it is greater than its neighbours.

// Example :

//  arr[] = {1,3,20,4,2,0}

// Condition for Peak element : 
//                      arr[i] > arr[i-1] and arr[i] >arr[i+1]

//  Edge Cases:
//                    If size of array is 1, that element will be peak element. For extreme indexes, there's only 1 neighbour.

// Naive Solution : Brute Force

#include <iostream>

using namespace std;

int findPeak(int arr[], int n) { 
    if (n == 1) {
        return 0;
    }

    if (arr[0] > arr[1]) {
        return 0;
    }

    if (arr[n-1] > arr[n-2]) {
        return n - 1;
    }

    for (int i = 1; i < n - 1; i++) { 
        if (arr[i] > arr[i-1] && arr[i] > arr[i+1]){
            return i;
        }
    }
    
    return -1; // peak element not found
}

int main() {
    int arr[] = {1,3,20,4,2,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    int peakIndex = findPeak(arr, n);
    if (peakIndex != -1) {
        cout << "Peak element found at index " << peakIndex << endl;
    } else {
        cout << "Peak element not found" << endl;
    }
    return 0;
}
// Output
// Peak element found at index 2
// Time complexity: O(n)

// Auxiliary Space: O(1)

// Efficient solution using Divide and Conquer

// The idea is based on the technique of Binary Search to check if the middle element is the peak element or not.

// If middle element is peak, return it's index as result.
// If middle element is not the peak, then we reduce our search space to the left or right of middle based on some condition
// Implementation :

#include <iostream>

using namespace std;

int findPeak(int arr[], int lo, int hi, int n) { 
    int mid = (lo + hi) / 2;

    if ((mid == 0 || arr[mid - 1] < arr[mid]) && (mid == n - 1 || arr[mid + 1] < arr[mid])) {
        return mid; 
    } else if (mid > 0 && arr[mid - 1] > arr[mid]) { 
        return findPeak(arr, lo, (mid - 1), n); 
    } else {
        return findPeak(arr, (mid + 1), hi, n);
    }
}

int main() {
    int arr[] = {1, 3, 20, 4, 2, 0};
    int n = sizeof(arr)/sizeof(arr[0]);
    int peakIndex = findPeak(arr, 0, n-1, n);
    if (peakIndex != -1) {
        cout << "Peak element found at index " << peakIndex << endl;
    } else {
        cout << "Peak element not found" << endl;
    }
    return 0;
}

// Time Complexity: O(log N), Where N is the number of elements in the input array. 
// Auxiliary Space: O(log N)

