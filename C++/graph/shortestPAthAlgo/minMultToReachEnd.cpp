#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define f(i, a, b) for(int i=a;i<b;i++)
#define all(x) x.begin(),x.end()
#define vprint(v) for (auto& elem : v) cout << elem << " "; cout << endl;
#define mprint(m) for (auto it:m) cout<<it.first<<" : "<<it.second<<endl; cout<<endl;
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

int minimumMultiplications(vector<int>& arr, int start, int end) {
    queue<pair<int,int>> q;
    q.push({start,0});
    vector<int> dist(100000, 1e9);

    dist[start]=0;
    int mod=100000;

    while(!q.empty()){
        int node=q.front().first;
        int steps=q.front().second;
        q.pop();

        for(auto it: arr){
            int num = (it*node) % mod;
            if(steps+1< dist[num]){
                dist[num]=steps+1;
                if(num==end)return steps+1;
                q.push({num, steps+1});

            }
        }
    }
}

int main() {
    FAST_IO;
    
    return 0;
}
//by ad73prem