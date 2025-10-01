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



vector<vector<int>> filterOddLengthSubarrays(vector<vector<int>>& subarrays) {
    vector<vector<int>> result;
    for (auto& sub : subarrays) {
        if (sub.size() % 2 == 1) {
            result.push_back(sub);
        }
    }
    return result;
}



vector<vector<int>> getSubarraysWithMedianK(vector<vector<int>>& subarrays, int k) {
    vector<vector<int>> result;
    for (auto& sub : subarrays) {
        vector<int> temp = sub;
        sort(temp.begin(), temp.end());
        int m = temp.size();
        int median = m % 2 == 1 ? temp[m / 2] : (temp[m / 2 - 1] + temp[m / 2]) / 2;
        if (median == k) {
            result.push_back(sub);
        }
    }
    return result;
}

long getSpecialSubarrays(int efficiency_count, int* efficiency, int k){
    int n = efficiency_count;  // number of elements
    vector<int> vec(efficiency, efficiency + n);
    vector<vector<int>> allsubarrays=getAllSubarrays(vec);
    vector<vector<int>> oddlengthsubarrays=filterOddLengthSubarrays(allsubarrays);
    int x=efficiency[k-1];
    vector<vector<int>> subarrayswithmedian=getSubarraysWithMedianK(oddlengthsubarrays,x);
    return subarrayswithmedian.size();
}

int main() {
    FAST_IO;
    // vint eff={5,3,1,4,7,7};
    // vmat res=getAllSubarrays(eff);
    // vmatprint(res);

    // cout<<endl;
    // vmat resodd=filterOddLengthSubarrays(res);
    // vmatprint(resodd);

    // cout<<endl;
    // vmat fin=getSubarraysWithMedianK(resodd,4);
    // vmatprint(fin);
    int efficiency[3]={1,2,3};
    cout<<getSpecialSubarrays(3, efficiency, 1);
    return 0;
}
//by ad73prem