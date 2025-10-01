// Counting Inversions using Merge Sort

// Inversion Count for an array indicates – how far (or close) the array is from being sorted. If the array is already sorted, then the inversion count is 0, but if the array is sorted in reverse order, the inversion count is the maximum. 

// Given an array a[]. The task is to find the inversion count of a[]. Where two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.

// Examples: 

// Input: arr[] = {8, 4, 2, 1}
// Output: 6
// Explanation: Given array has six inversions: (8, 4), (4, 2), (8, 2), (8, 1), (4, 1), (2, 1).

// Input: arr[] = {1, 20, 6, 4, 5}
// Output: 5
// Explanation: Given array has five inversions: (20, 6), (20, 4), (20, 5), (6, 4), (6, 5). 

// Naive Approach:

// Traverse through the array, and for every index, find the number of smaller elements on its right side of the array. This can be done using a nested loop. Sum up the counts for all indices in the array and print the sum.

// Follow the below steps to Implement the idea:

// Traverse through the array from start to end
// For every element, find the count of elements smaller than the current number up to that index using another loop.
// Sum up the count of inversion for every index.
// Print the count of inversions.
// Below is the Implementation of the above approach

// C++ program to Count Inversions
// in an array
#include <bits/stdc++.h>
using namespace std;

int getInvCount(int arr[], int n)
{
	int inv_count = 0;
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (arr[i] > arr[j])
				inv_count++;

	return inv_count;
}

// Driver Code
int main()
{
	int arr[] = { 1, 20, 6, 4, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << " Number of inversions are "
		<< getInvCount(arr, n);
	return 0;
}
Time Complexity: O(N2), Two nested loops are needed to traverse the array from start to end.
Auxiliary Space: O(1), No extra space is required.

Counting Inversions using Merge Sort

Illustration:

Suppose the number of inversions in the left half and right half of the array (let be inv1 and inv2); what kinds of inversions are not accounted for in Inv1 + Inv2? The answer is – the inversions that need to be counted during the merge step. Therefore, to get the total number of inversions that needs to be added are the number of inversions in the left subarray, right subarray, and merge().

inv_count1

How to get the number of inversions in merge()? 
In merge process, let i is used for indexing left sub-array and j for right sub-array. At any step in merge(), if a[i] is greater than a[j], then there are (mid – i) inversions. because left and right subarrays are sorted, so all the remaining elements in left-subarray (a[i+1], a[i+2] … a[mid]) will be greater than a[j]

#include <bits/stdc++.h>
using namespace std;

vector<int> merge(vector<int> a, vector<int> b, long long &invCount) {
    int n = a.size();
    int m = b.size();

    a.push_back(INT_MAX); 
    b.push_back(INT_MAX); 

    vector<int> res(n + m);

    int i = 0, j = 0;
    for (int k = 0; k < n + m; k++) {
        if (a[i] <= b[j]) {
            res[k] = a[i];
            i++;
            invCount += j;
        } else {
            res[k] = b[j];
            j++;
        }
    }

    return res;
}

vector<int> mergeSort(vector<int> v, long long &invCount) { 
    int n = v.size();
    if (n == 1) {
        return v;
    }

    vector<int> left(v.begin(), v.begin() + n / 2); 
    vector<int> right(v.begin() + n / 2, v.end()); 

    left = mergeSort(left, invCount); 
    right = mergeSort(right, invCount); 

    return merge(left, right, invCount); 
}

int main() {
    int arr[] = { 1, 20, 6, 4, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> v(arr, arr + n);
    long long invCount = 0; 
    vector<int> sorted = mergeSort(v, invCount); 
    cout << "Number of inversions are " << invCount << endl; 
    return 0;
}