// Make Permutation

// Make Permutations
// You are given an array of integers a of length n. Each element of the array is colored either blue or red. There are no unpainted elements in the array. One of the two operations described below can be applied on an array in a single step:

// either you can select blue element and decrease its value by 1
// or you can select any red element and increase the value by 1.
// Situations in which there are no elements of some color at all are also possible. For example, if the whole array is colored blue or red, one of the operations becomes unavailable. Determine whether it is possible to make 0 or more steps such that the resulting array is a permutation of numbers from 1 to n.

// Example:
// Input:
// 1 2 5 2
// B R B R
// Output: Yes
// Explanation: 
// 1 -> 1
// 2 -> 2
// 5 -> 3
// 2 -> 4
// Greedy Approach
// The intuition behind the solution is to use a simple and efficient approach to check whether it is possible to obtain a permutation of 1 to n using the given array and color arrays.

// The first step in the algorithm is to separate the elements of the input array into two vectors based on their color. This is because the two types of elements (red and blue) require different operations to transform the array into a permutation of 1 to n.

// Next, we sort both vectors in non-decreasing order. Sorting allows us to easily compare each element with its corresponding index later on.

// Then, we iterate over the blue vector and check whether any element is already equal to its corresponding index plus one. If such an element exists, it means that we cannot transform the array into a permutation of 1 to n, since there will be duplicate elements. This is because elements with different indices are required to have different values for a permutation to exist.

// Similarly, we iterate over the red vector and check whether any element is greater than n-i, where i is the current index. If such an element exists, it means that we cannot transform the array into a permutation of 1 to n, since there will be at least one element greater than n. This is because we must have n distinct elements in a permutation of 1 to n.

// If neither of the above conditions is met, it means that it is possible to transform the array into a permutation of 1 to n, and hence, we return true.

bool makePermutation(vector<int> &a, string &colour){
	int n = a.size();
  	vector<int> red, blue;
  	
  	for(int i = 0; i < n; i++){
    	if(colour[i] == 'R')
          	red.emplace_back(a[i]);
        else
          	blue.emplace_back(a[i]);
    }
  
  	sort(blue.begin(), blue.end());
  	sort(red.begin(), red.end());
  
  	for(int i = 0; i < blue.size(); i++){
    	if(blue[i] == i + 1)
          	return false;
    }
  
  	for(int i = 0; i < red.size(); i++){
    	if(red[i] > n - i)
          	return false;
    }
  
  	return true;
}