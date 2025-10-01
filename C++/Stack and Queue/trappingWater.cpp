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
    vint height={4,2,0,3,2,5};
    int n=height.size();
    vint prefixmax(n);
    vint suffixmax(n);
    prefixmax[0]=height[0];
    suffixmax[n-1]=height[n-1];
    for(int i=1;i<n;i++){
        prefixmax[i]=max(prefixmax[i-1],height[i]);
    }
    for(int i=n-2;i>=0;i--){
        suffixmax[i]=max(suffixmax[i+1],height[i]);
    }
    // vprint(prefixmax);
    // vprint(suffixmax);

    int total=0;
    for(int i=0;i<n;i++){
        if(height[i]<prefixmax[i]&&height[i]<suffixmax[i]){
            total+=min(prefixmax[i],suffixmax[i])-height[i];
        }
    }
    cout<<total<<endl;
    return 0;
}
//by ad73prem