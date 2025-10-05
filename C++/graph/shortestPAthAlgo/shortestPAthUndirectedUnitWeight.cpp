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

vector<int> shortesPath(vector<vector<int>> & graph){
    int n=graph.size();
    vector<int> distance(n, INT_MAX);
    queue<pair<int,int>> q; //queue to store for bfs

    q.push({0,0});//push the source into the queue
    while(!q.empty()){
        int node=q.front().first;
        int dist=q.front().second;
        q.pop();
        if(distance[node]>dist){
            distance[node]=dist;
        }
        for(auto it: graph[node]){
            if(distance[it]>dist+1){
                q.push({it, dist+1});
            }
        }
    }
    vprint(distance);
}

int main() {
    FAST_IO;
    vector<vector<int>> graph={
        {1,3},
        {0,2,3},
        {1,6},
        {0,1,4},
        {3,5},
        {4,6},
        {2,5,7,8},
        {6,8},
        {6,7}
    };
    shortesPath(graph);
    return 0;
}
//by ad73prem