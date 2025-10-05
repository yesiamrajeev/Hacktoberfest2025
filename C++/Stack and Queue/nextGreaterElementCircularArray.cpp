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



int main() {
    FAST_IO;
    vint nums={2,10,12,1,11};
    int n=nums.size();
    vint ans(n);
    stack<int> st;
    for(int i=2*n-1;i>=0;i--){
        while(!st.empty()&&st.top()<=nums[i%n])st.pop();
        if(i<n)ans[i]=st.empty()?-1:st.top();
        st.push(nums[i%n]);
    }
    vprint(ans);
    return 0;
}
//by ad73prem