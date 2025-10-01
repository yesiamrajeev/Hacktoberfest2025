// Minimum Range Problem

// Given a function F(x)  = (x2 + b * x + c) / sinx ,

// Find the minimum value of the over the range 0 < x < π / 2.

// Input Format:
// The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases is as follows:

// Each Line of Testcase contain b and c
// Output Format:
// For each test case, output the minimum value of f(x) over the given range. Absolute error of 10-9 is allowed.

// Constraints:
// 1 <= T <= 15000
// 1 <= Bi, Ci <= 20

// Example:

// Input:
// 1
// 2 2

// Output:
// 5.883172561

#include <bits/stdc++.h>
using namespace std;

const double PI = 3.14159265359;
const double eps = 1e-9;

double operation(double x, double b, double c) {
    return (x * x + b * x + c) / sin(x);
}

void solve() {
    double b, c;
    cin >> b >> c;
    double l = 0 + eps, r = PI / 2 - eps;
    while (r - l > eps) {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;

        double f1 = operation(m1, b, c);
        double f2 = operation(m2, b, c);
        if (f1 > f2)
            l = m1;
        else
            r = m2;
    }

    cout << setprecision(9) << fixed << operation(l, b, c) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    

    return 0;
}