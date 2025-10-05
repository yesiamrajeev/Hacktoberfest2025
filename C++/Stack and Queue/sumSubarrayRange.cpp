#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define f(i, a, b) for(int i=a;i<b;i++)
#define all(x) x.begin(),x.end()
#define vprint(v) for (auto& elem : v) cout << elem << " "; cout << endl;
#define vmatprint(vv) for (auto& row : vv) { for (auto& elem : row) cout << elem << " "; cout << endl; } cout << endl;
#define mprint(m) for (auto it : m) cout << it.first << " : " << it.second << endl; cout << endl;
#define vint vector<int>
#define vstring vector<string>
#define vmat vector<vector<int>>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mii map<int,int>
#define mll map<ll,ll>

const int INF = 1e9;
const ll MOD = 1e9+7;

vector<vector<int>> getAllSubarrays(vector<int>& arr) {
    vector<vector<int>> result;
    int n = arr.size();
    for (int i = 0; i < n; ++i) {
        vector<int> subarray;
        for (int j = i; j < n; ++j) {
            subarray.push_back(arr[j]);
            result.push_back(subarray);
        }
    }
    return result;
}

int findRange(vector<int>& arr) {
    int minVal = *min_element(arr.begin(), arr.end());
    int maxVal = *max_element(arr.begin(), arr.end());
    return maxVal - minVal;
}

long long subArrayRanges(vector<int>& nums) {
    vector<vector<int>> allSubarrays = getAllSubarrays(nums);
    long long totalRangeSum = 0;

    for (int i=0;i<allSubarrays.size();i++) {
        vector<int> subarray = allSubarrays[i];
        totalRangeSum += findRange(subarray);
    }

    return totalRangeSum;        
}

int main() {
    FAST_IO;
    vint nums = {4,-2,-3,4,1};
    cout << "Total sum of subarray ranges: " << subArrayRanges(nums) << endl;
    return 0;
}
//by ad73prem