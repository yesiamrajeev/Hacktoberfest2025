// Count ways to reach nth stair

// Count ways to reach the n’th stair
// There are n stairs, a person standing at the bottom wants to reach the top. The person can climb either 1 stair or 2 stairs at a time. Count the number of ways, the person can reach the top.

// stairs
// Examples: 

// Input: n = 1
// Output: 1
// There is only one way to climb 1 stair

// Input: n = 2
// Output: 2
// There are two ways: (1, 1) and (2)

// Input: n = 4
// Output: 5
// (1, 1, 1, 1), (1, 1, 2), (2, 1, 1), (1, 2, 1), (2, 2)
// Recursive Solution
// The first method uses the technique of recursion to solve this problem.
// Approach: We can easily find the recursive nature in the above problem. The person can reach nth stair from either (n-1)th stair or from (n-2)th stair. Hence, for each stair n, we try to find out the number of ways to reach n-1th stair and n-2th stair and add them to give the answer for the nth stair. Therefore the expression for such an approach comes out to be : 

// ways(n) = ways(n-1) + ways(n-2)
// The above expression is actually the expression for Fibonacci numbers, but there is one thing to notice, the value of ways(n) is equal to fibonacci(n+1). 

// ways(1) = fib(2) = 1
// ways(2) = fib(3) = 2
// ways(3) = fib(4) = 3
// For a better understanding, let’s refer to the recursion tree below -: 

// Input: N = 4

//                   fib(5)
//            '3'  /        \   '2'
//                /          \
//            fib(4)         fib(3)
//      '2'  /      \ '1'   /      \  
//          /        \     /        \ 
//      fib(3)     fib(2)fib(2)      fib(1) 
//      /    \ '1' /   \ '0'
// '1' /   '1'\   /     \ 
//    /        \ fib(1) fib(0) 
// fib(2)     fib(1)
// So we can use the function for Fibonacci numbers to find the value of ways(n).

#include <bits/stdc++.h>
using namespace std;

int fib(int n){
	if (n <= 1)
		return n;
	return fib(n - 1) + fib(n - 2);
}

int countWays(int s){
	return fib(s + 1);
}

int main(){
	int s = 4;

	cout << "Number of ways = " << countWays(s);

	return 0;
}

// DP Solution
// Approach: We create a table res[] in bottom-up manner using the following relation: 

// res[i] = res[i] + res[i-j] for every (i-j) >= 0
// such that the ith index of the array will contain the number of ways required to reach the ith step considering all the possibilities of climbing (i.e. from 1 to i).

#include <iostream>
using namespace std;

int countWaysUtil(int n, int m){
    int res[n];
    res[0] = 1;
    res[1] = 1;
     
    for(int i = 2; i < n; i++){
       res[i] = 0;
        
       for(int j = 1; j <= m && j <= i; j++)
          res[i] += res[i - j];
    }
    return res[n - 1];
}

int countWays(int s, int m){
    return countWaysUtil(s + 1, m);
}

int main(){
    int s = 4, m = 2;
     
    cout << "Number of ways = "
         << countWays(s, m);
          
    return 0;
}