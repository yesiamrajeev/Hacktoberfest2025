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

int trap(vector<int>& height) {
        vector<int> nums=height;
        int n=nums.size();
        int lmax=0;
        int rmax=0;
        int total=0;
        int l=0;
        int r=n-1;
        while(l<r){
            if(nums[l]<=nums[r]){
                if(lmax>nums[l]){
                    total+=lmax-nums[l];
                }
                else{
                    lmax=nums[l];
                }
                l=l+1;
            }
            else{
                if(rmax>nums[r]){
                    total+=rmax-nums[r];
                }
                else{
                    rmax=nums[r];
                }
            }
        }
        return total;
    }

int main() {
    FAST_IO;
    vint nums={0,1,0,2,1,0,1,3,2,1,2,1};
    int n=nums.size();
    int lmax=0;
    int rmax=0;
    int total=0;
    int l=0;
    int r=n-1;
    while(l<r){
        if(nums[l]<=nums[r]){
            if(lmax>nums[l]){
                total+=lmax-nums[l];
            }
            else{
                lmax=nums[l];
            }
            l=l+1;
        }
        else{
            if(rmax>nums[r]){
                total+=rmax-nums[r];
            }
            else{
                rmax=nums[r];
            }
            r=r-1;
        }
    }
    cout<<trap(nums);
    return 0;
}
//by ad73prem