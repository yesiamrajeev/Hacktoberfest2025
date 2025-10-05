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

void subsetGenerate(vector<vector<int>> &res, vint curr, vint nums, int i){
    if(i==nums.size()){
        res.push_back(curr);
        return;
    }

    curr.push_back(nums[i]);
    subsetGenerate(res,curr,nums,i+1);

    curr.pop_back();
    subsetGenerate(res,curr,nums,i+1);
}



vector<vector<int>> makeSubarray(vector<int> nums){
    vmat res;
    vint curr;
    subsetGenerate(res,curr,nums,0);
    return res;
}

int sumSubarrayMins(vector<int>& arr) {
    vmat subarrays=makeSubarray(arr);
    vmatprint(subarrays);
    int ans=0;
    int mn=0;
    for(int i=0;i<subarrays.size();i++){
        mn=INT_MAX;
        for(int j=0;j<subarrays[i].size();j++){
            mn=min(subarrays[i][j],mn);
        }
        cout<<mn<<endl;
        cout<<"total : "<<ans<<endl;
        ans+=mn;
    }   
    return ans;     
}

int main() {
    FAST_IO;
    vint nums={3,1,2,4};
    // vmat res=makeSubarray(nums);
    // vmatprint(res);
    cout<<sumSubarrayMins(nums);
    return 0;
}
//by ad73prem