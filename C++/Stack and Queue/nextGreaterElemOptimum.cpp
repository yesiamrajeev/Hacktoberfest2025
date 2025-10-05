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
    stack<int> st;
    vint nums={4,12,5,3,1,2,5,3,1,2,4,6};
    vint nge(nums.size());
    for(int i=nums.size()-1;i>=0;i--){
        while(!st.empty()&&st.top()<=nums[i]){
            st.pop();
        }
        if(st.empty()){
            nge[i]=-1; 
        }
        else{
            nge[i]=st.top();
        }
        st.push(nums[i]);
    }
    vprint(nums);
    vprint(nge);
    return 0;
}
//by ad73prem