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

void topoSort(int node, vector<vector<pair<int,int>>>& graph, vector<int>& vis, stack<int> &st){
    vis[node]=1;
    for(auto it: graph[node]){
        if(!vis[it.first]){
            topoSort(it.first, graph, vis, st);
        }
    }

    st.push(node);
}

vector<int> findPath(vector<vector<pair<int,int>>>& graph){
    //find topo
    int n=graph.size();
    vector<int> vis(n,0);
    stack<int> st;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            topoSort(i,graph,vis,st);
        }
    }

    //do the ralxation
    vector<int> dis(n, INT_MAX);
    dis[0]=0;
    while(!st.empty()){
        int node=st.top();
        st.pop();

        for(auto it: graph[node]){
            if(dis[node]+it.second<dis[it.first]){
                dis[it.first]= dis[node]+it.second;
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