#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// --- Brute-Force Approach ---
// Time Complexity: O(N)
// Space Complexity: O(D)
vector<int> leftRotateBruteForce(vector<int> arr, int n, int d)
{
  d = d % n;
  if (d == 0)
    return arr;

  vector<int> temp;
  for (int i = 0; i < d; i++)
  {
    temp.push_back(arr[i]);
  }

  for (int i = d; i < n; i++)
  {
    arr[i - d] = arr[i];
  }

  for (int i = 0; i < d; i++)
  {
    arr[n - d + i] = temp[i];
  }

  return arr;
}

// --- Optimal Approach (Reversal Algorithm) ---
// Time Complexity: O(N)
// Space Complexity: O(1)
void leftRotateOptimal(vector<int> &arr, int n, int d)
{
  d = d % n;
  if (d == 0)
    return;

  reverse(arr.begin(), arr.begin() + d);

  reverse(arr.begin() + d, arr.end());

  reverse(arr.begin(), arr.end());
}

int main()
{
  int size;
  cout << "Enter the size of the array: ";
  cin >> size;

  vector<int> v(size);
  cout << "Enter " << size << " elements: ";
  for (int i = 0; i < size; i++)
  {
    cin >> v[i];
  }

  int d;
  cout << "Enter the number of positions to rotate left: ";
  cin >> d;

  cout << "\nOriginal Array: ";
  for (int val : v)
  {
    cout << val << " ";
  }
  cout << endl;

  // --- Testing Brute-Force Solution ---
  vector<int> brute_result = leftRotateBruteForce(v, size, d);
  cout << "\nAfter rotation (Brute-Force): ";
  for (int val : brute_result)
  {
    cout << val << " ";
  }
  cout << endl;

  // --- Testing Optimal Solution ---
  vector<int> optimal_v = v;
  leftRotateOptimal(optimal_v, size, d);
  cout << "After rotation (Optimal):    ";
  for (int val : optimal_v)
  {
    cout << val << " ";
  }
  cout << endl;

  return 0;
}
