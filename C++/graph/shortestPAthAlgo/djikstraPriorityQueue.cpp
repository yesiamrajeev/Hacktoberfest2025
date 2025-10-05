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

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S){
    priority_queue<
        pair<int,int>, //type of elements stored here(distance,node)
        vector<pair<int,int>>,  //the underllying contatiner used: a vector
        greater<pair<int,int>>   //the comparator: smallest element comes first
    > pq;


    vector<int> dist(V); //distance vector
    for(int i=0;i<V;i++){
        dist[i]=INT_MAX;
    }

    dist[S]=0;
    pq.push({0,S});

    while(!pq.empty()){
        int dis= pq.top().first;
        int node= pq.top().second;

        pq.pop();

        for(auto it: adj[node]){
            int edgeWeight = it[1];
            int adjNode = it[0];

            if(dis+edgeWeight< dist[adjNode]){
                dist[adjNode]= dis+edgeWeight;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
}

int main() {
    FAST_IO;
    
    return 0;
}
//by ad73prem