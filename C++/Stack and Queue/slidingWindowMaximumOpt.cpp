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

void printdq(deque<int> dq){
    while(!dq.empty()){
        cout<<dq.front()<<" ";
        dq.pop_front();
    }
    cout<<endl;
}

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque <int> dq;
    vector<int> ans;
    for(int i=0;i<nums.size();i++){
        cout<<"for "<<i<<" : "<<endl;
        printdq(dq);

        //kya window filled hai. agar filled hai to hi naa saamne wala element ko nikaalenge
        if(!dq.empty() && dq.front()==i-k){
            dq.pop_front();
        }


        //this makes sur ethat the front of a window always has windo's maximum.
        while(!dq.empty() && nums[dq.back()] < nums[i]){
            dq.pop_back();
        }
        
        dq.push_back(i);

        //we have completed the window
        if(i>=k-1){

            //this time this will only be the maximum. if this weren;t the max, it would have already been removed
            ans.push_back(nums[dq.front()]);
        }
        
    }
    return ans;
}

int main() {
    FAST_IO;
    int i, j, n, k = 3, x;
  vector < int > arr {1,3,-1,-3,5,3,6,7};
  vector < int > ans;
  ans = maxSlidingWindow(arr, k);
  cout << "Maximum element in every " << k << " window " << endl;
  for (i = 0; i < ans.size(); i++)
    cout << ans[i] << " ";
  return 0;
    return 0;
}
//by ad73prem