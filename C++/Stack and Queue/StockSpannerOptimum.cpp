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


class StockSpanner{
    stack<pair<int,int>> st;
    int ind=-1;
    StockSpanner(){
        ind=-1;
        while(!st.empty()){
            st.pop();
        }
    }

    int next(int price){
        ind=ind+1;
        int ans;
        while(!st.empty() && st.top().first<=price) st.pop();

        ans=ind-(st.empty() ? -1 : st.top().second);

        st.push({price,ind});

        return ans;
    }

};

vint prevGreaterElement(vint nums){
    int n=nums.size();
    stack<int> st;
    vint ans(n,-1);

    for(int i=0;i<n;i++){
        while(!st.empty() && nums[st.top()]<nums[i]){
            st.pop();
        }
        // cout<<" for "<<i<<" : ";
        // printStack(st);
        if(!st.empty()){
            ans[i]=st.top();
        }
        st.push(i);
    }
    return ans;
}

int main() {
    FAST_IO;
    
    return 0;
}
//by ad73prem