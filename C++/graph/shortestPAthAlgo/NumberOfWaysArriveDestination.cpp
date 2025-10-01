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

int countPaths(int n, vector<vector<int>>& roads) {
    //make the adjacency list
    vector<vector<pair<int,int>>> adj(n);
    for(auto it:roads){
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }

    vector<long long> dist(n, 1e18); //distance array
    vector<long long> ways(n, 0); //ways array

    priority_queue<
        pair<long long,int>, //type of elements stored here(distance,node)
        vector<pair<long long,int>>,  //the underllying contatiner used: a vector
        greater<pair<long long,int>>   //the comparator: smallest element comes first
    > q;
    q.push({0,0});
    dist[0]=0;
    ways[0]=1;

    while(!q.empty()){
        auto it= q.top();
        int node= it.second;
        long long distance= it.first;
        q.pop();
        // cout<<"node : "<<node<<" distance : "<<distance<<endl;

        for(auto iter: adj[node]){
            int adjNode= iter.first;
            int edgeWeight= iter.second;
            // cout<<"adjacent Node : "<<adjNode<<endl;
            // cout<<"edgeweight : "<<edgeWeight<<endl;
            if(distance+edgeWeight< dist[adjNode]){
                dist[adjNode]= distance+edgeWeight;
                // cout<<"dist[adjNode]: "<<distance+edgeWeight<<endl;
                q.push({distance+ edgeWeight, adjNode});
                ways[adjNode]=ways[node];
            }

            else if(dist[adjNode]== distance+edgeWeight){
                ways[adjNode]= (ways[adjNode]+ways[node])%MOD;
            }
        }
        // vprint(dist);
        // vprint(ways)
    }
    // vprint(dist);
    // vprint(ways);
    return ways[n-1];
}

int main() {
    FAST_IO;
    vector<vector<int>> roads={
        {0,6,7},
        {0,1,2},
        {1,2,3},
        {1,3,3},
        {6,3,3},
        {3,5,1},
        {6,5,1},
        {2,5,1},
        {0,4,5},
        {4,6,2}
    };
    cout<<countPaths(7, roads);
    return 0;
}
//by ad73prem