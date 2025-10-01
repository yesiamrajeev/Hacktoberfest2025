// Ternary Search

// Find the minimum value of the function 

// f(x) = (x2 +b * x+c) / sin(x)
//  Ternary search is a decrease(by constant) and conquer algorithm that can be used to find an element in an array. It is similar to binary search where we divide the array into two parts but in this algorithm, we divide the given array into three parts and determine which has the key (searched element). We can divide the array into three parts by taking mid1 and mid2 which can be calculated as shown below. Initially, l and r will be equal to 0 and n-1 respectively, where n is the length of the array. 

// It is same as the binary search. The only difference is that, it reduces the time complexity a bit more. the algorithm involves ‘N’ steps. The searchable range would be the size = 3^N. Inversely, the number of steps needed to find the element is the log of the size of the collection. So the runtime is O(log N base 3).

 #include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

#define PI 3.141592653589793

const double EPS = 1e-9;

double f(double x) {
    // Function to be minimized
    return sin(x) + cos(x);
}

double ternarySearch(double lo, double hi) {
    while (hi - lo > EPS) {
        double mid1 = lo + (hi - lo) / 3.0;
        double mid2 = hi - (hi - lo) / 3.0;
        double y1 = f(mid1);
        double y2 = f(mid2);
        if (y1 > y2) {
            lo = mid1;
        } else {
            hi = mid2;
        }
    }
    return f(lo);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double lo = 0.0, hi = PI / 2.0;
    double ans = ternarySearch(lo, hi);
    cout << fixed << setprecision(9) << ans << endl;

    return 0;
}