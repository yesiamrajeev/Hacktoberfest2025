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
    vint nums={3,1,2,4};
    int total=0;
    int mn;
    vmat sub;
    vint temp;
    for(int i=0;i<nums.size();i++){
        for (int j=i;j<nums.size();j++){
            temp.push_back(nums[j]);
            sub.push_back(temp);
        }
        temp.clear();
    }
    
    for(int i=0;i<sub.size();i++){
        mn=INT_MAX;
        for(int j=0;j<sub[i].size();j++){
            mn=min(mn,sub[i][j]);
        }
        total+=mn;
    }
    cout<<total;
    return 0;
}
//by ad73prem