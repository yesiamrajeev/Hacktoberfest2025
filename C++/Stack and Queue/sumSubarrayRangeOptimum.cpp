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

vint nextSmallerElement(vint nums){
    int n=nums.size();
    vint nse(n,n);
    stack<int> st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && nums[i]<=nums[st.top()]){
            st.pop();
        }
        if(!st.empty()){
            nse[i]=st.top();
        }
        st.push(i);
    }
    return nse;
}

vint nextGreaterElement(vint nums){
    int n=nums.size();
    vint nge(n,n);
    stack<int> st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && nums[i]>=nums[st.top()]){
            st.pop();
        }
        if(!st.empty()){
            nge[i]=st.top();
        }
        st.push(i);
    }
    return nge;
}

vint prevSmallerElement(vint nums){
    int n=nums.size();
    vint pse(n,-1);
    stack<int> st;
    for(int i=0;i<n;i++){
        while(!st.empty() && nums[i]<nums[st.top()]){
            st.pop();
        }
        if(!st.empty()){
            pse[i]=st.top();
        }
        st.push(i);
    }
    return pse;
}

vint prevGreaterElement(vint nums){
    int n=nums.size();
    vint pge(n,-1);
    stack<int> st;
    for(int i=0;i<n;i++){
        while(!st.empty() && nums[i]>nums[st.top()]){
            st.pop();
        }
        if(!st.empty()){
            pge[i]=st.top();
        }
        st.push(i);
    }
    return pge;
}

long long sumSubarrayMin(vint nums){
    int n=nums.size();
    vint nse=nextSmallerElement(nums);
    vint pse=prevSmallerElement(nums);
    ll total=0;
    for(int i=0;i<n;i++){
        int left=i-pse[i];
        int right=nse[i]-i;
        total+=(left*right*nums[i]);
    }
    return total;
}

ll sumSubarrayMax(vint nums){
    int n=nums.size();
    vint nge=nextGreaterElement(nums);
    vint pge=prevGreaterElement(nums);
    ll total=0;
    for(int i=0;i<n;i++){
        int left=i-pge[i];
        int right=nge[i]-i;
        total+=(left*right*nums[i]);
    }
    return total;
}

long long subArrayRanges(vector<int>& nums) {
    ll a=sumSubarrayMin(nums);
    ll b=sumSubarrayMax(nums);
    return b-a;
}

int main() {
    FAST_IO;
    vint nums={4,-2,-3,4,1};
    // vprint(nextSmallerElement(nums));
    // vprint(nextGreaterElement(nums));
    // vprint(prevSmallerElement(nums));
    // vprint(prevGreaterElement(nums));
    cout<<subArrayRanges(nums);
    return 0;
}
//by ad73prem