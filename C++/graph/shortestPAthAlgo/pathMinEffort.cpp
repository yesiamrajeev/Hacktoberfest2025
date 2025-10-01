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

int minimumEffortPath(vector<vector<int>>& heights) {
    //{difference,{row,col}}
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > pq;

    int n=heights.size();
    int m=heights[0].size();

    vector<vector<int>> diff(n, vector<int> (m,1e9));
    pq.push({0,{0,0}});
    diff[0][0]=0;

    vector<int> drow={-1,0,1,0};
    vector<int> dcol={0,1,0,-1};

    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int difference= it.first;
        int r=it.second.first;
        int c=it.second.second;

        if(r==n-1 && c==m-1)return difference;

        for(int i=0;i<4;i++){
            int nrow=r+drow[i];
            int ncol=c+dcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m ){
                int newEffort= max(abs(heights[r][c]-heights[nrow][ncol]), difference);
                if(newEffort < diff[nrow][ncol]){
                    pq.push({newEffort,{nrow,ncol}});
                    diff[nrow][ncol]= newEffort;
                }
            }
        }
    }
    return 0;
}

int main() {
    FAST_IO;
    
    return 0;
}
//by ad73prem