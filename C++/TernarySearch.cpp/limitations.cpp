// In what cases does it fail ?

// Why is Binary Search preferred over Ternary Search?

// The following is a simple recursive Binary Search function in C++ 
// CPP program for the above approach
#include <bits/stdc++.h>
using namespace std;


// A recursive binary search function. It returns location of x in
// given array arr[l..r] is present, otherwise -1
int binarySearch(int arr[], int l, int r, int x)
{
if (r >= l)
{
		int mid = l + (r - l)/2;

		// If the element is present at the middle itself
		if (arr[mid] == x) return mid;

		// If element is smaller than mid, then it can only be present
		// in left subarray
		if (arr[mid] > x) return binarySearch(arr, l, mid-1, x);

		// Else the element can only be present in right subarray
		return binarySearch(arr, mid+1, r, x);
}

// We reach here when element is not present in array
return -1;
}
The following is a simple recursive Ternary Search function :
// A recursive ternary search function. It returns location of x in
// given array arr[l..r] is present, otherwise -1
int ternarySearch(int arr[], int l, int r, int x)
{
if (r >= l)
{
		int mid1 = l + (r - l)/3;
		int mid2 = mid1 + (r - l)/3;

		// If x is present at the mid1
		if (arr[mid1] == x) return mid1;

		// If x is present at the mid2
		if (arr[mid2] == x) return mid2;

		// If x is present in left one-third
		if (arr[mid1] > x) return ternarySearch(arr, l, mid1-1, x);

		// If x is present in right one-third
		if (arr[mid2] < x) return ternarySearch(arr, mid2+1, r, x);

		// If x is present in middle one-third
		return ternarySearch(arr, mid1+1, mid2-1, x);
}
// We reach here when element is not present in array
return -1;
}

// Which of the above two does less comparisons in worst case? 
// From the first look, it seems the ternary search does less number of comparisons as it makes Log3n recursive calls, but binary search makes Log2n recursive calls. Let us take a closer look. 
// The following is recursive formula for counting comparisons in worst case of Binary Search. 

// T(n) = T(n/2) + 2,  T(1) = 1
// The following is recursive formula for counting comparisons in worst case of Ternary Search. 
 

//    T(n) = T(n/3) + 4, T(1) = 1
// In binary search, there are 2Log2n + 1 comparisons in worst case. In ternary search, there are 4Log3n + 1 comparisons in worst case. 
 

// Time Complexity for Binary search = 2clog2n + O(1)
// Time Complexity for Ternary search = 4clog3n + O(1)
// Therefore, the comparison of Ternary and Binary Searches boils down the comparison of expressions 2Log3n and Log2n . The value of 2Log3n can be written as (2 / Log23) * Log2n . Since the value of (2 / Log23) is more than one, Ternary Search does more comparisons than Binary Search in worst case.

 