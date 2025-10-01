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

int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    vector<vector<int>>dist(n,vector<int>(n,1e9));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                dist[i][j]=0;
            }
        }
    }

    //preping adj matrix
    for(auto it: edges){
        int from= it[0];
        int to= it[1];
        int wt= it[2];
        dist[from][to]=wt;
        dist[to][from]=wt;
    }

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }
    
    // for(auto it: dist){
    //     vprint(it);
    // }

    vector<int> temp(n,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(dist[i][j]<=distanceThreshold){
                temp[i]++;
            }
        }
    }
    int minimum=INT_MAX;
    for(auto it: temp){
        minimum=min(minimum, it);
    }
    vector<int> ans;
    // for(auto it: temp){
    //     if(it==minimum){
    //         ans.push_back(it);
    //     }
    // }

    for(int i=0;i<temp.size();i++){
        if(temp[i]==minimum){
            ans.push_back(i);
        }
    }

    // cout<<endl;
    // vprint(temp);
    // cout<<endl<<minimum<<endl;
    // cout<<"ans : "<<endl;
    // vprint(ans);
    if(ans.size()==1){
        return ans[0];
    }return ans[ans.size()-1];


    
    return 0;
}

int main() {
    FAST_IO;
    vector<vector<int>> mat={{0,1,2},{0,4,8},{1,2,3},{1,4,2},{2,3,1},{3,4,1}};
    cout<<"final answer : "<<findTheCity(5, mat, 2);
    return 0;
}
//by ad73prem