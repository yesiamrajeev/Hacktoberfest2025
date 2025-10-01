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

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<vector<pair<int,int>>> adj(n);
    for(auto it: flights){
        adj[it[0]].push_back({it[1],it[2]});
    }

    queue<pair<int,pair<int,int>>> q;
    q.push({0,{src,0}});   //stops, node, distance or cost
    //distance array
    vector<int> distance(n,1e9);
    distance[src]=0;


    while(!q.empty()){
        auto it= q.front();
        q.pop();
        int stops= it.first;
        int node= it.second.first;
        int dist= it.second.second;

        if(stops>k)continue;

        for(auto iter: adj[node]){
            int adjNode= iter.first;
            int edgeWeight= iter.second;

            if(dist+edgeWeight< distance[adjNode]){
                distance[adjNode]= dist+edgeWeight;
                q.push({stops+1,{adjNode, dist+edgeWeight}});
            }
        }
    }


    if(distance[dst]==1e9)return -1;
    return distance[dst];
}

int main() {
    FAST_IO;
    vector<vector<int>> flights={{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}};
    cout<<findCheapestPrice(4, flights, 0, 3, 1);
    return 0;
}
//by ad73prem