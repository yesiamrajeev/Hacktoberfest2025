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
 
vector<int> djikstra(int V, vector<vector<int>> adj[],int S){
    set<pair<int,int>> st;
    vector<int> distance(V, 1e9);

    st.insert({0,S});
    distance[S]=0;

    while(!st.empty()){
        auto it = *(st.begin()); //get the topmost element
        int node=it.second;
        int dist=it.first;
        st.erase(it);

        for(auto it: adj[node]){
            int adjNode= it[0];
            int edgeWeight= it[1];

            if(dist+edgeWeight < distance[adjNode]){
                //erase the existing redundant pair
                if(distance[adjNode]!= 1e9){
                    st.erase({distance[adjNode], adjNode});
                }
                distance[adjNode]=dist+edgeWeight;
                st.insert({distance[adjNode],adjNode});
            }
        }
        return distance;
    }
}

int main() {
    FAST_IO;
    
    return 0;
}
//by ad73prem