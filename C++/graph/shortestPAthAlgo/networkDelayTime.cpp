#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f(i, a, b) for (int i = a; i < b; i++)
#define all(x) x.begin(), x.end()
#define vprint(v)            \
    for (auto &elem : v)     \
        cout << elem << " "; \
    cout << endl;
#define mprint(m)                                       \
    for (auto it : m)                                   \
        cout << it.first << " : " << it.second << endl; \
    cout << endl;
#define vint vector<int>
#define vstring vector<string>
#define vmat vector<vector<int>>
#define FAST_IO                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mii map<int, int>
#define mll map<ll, ll>

const int INF = 1e9;
const ll MOD = 1e9 + 7;

int networkDelayTime(vector<vector<int>> &times, int n, int k)
{
    vector<vector<pair<int, int>>> adj(n+1);
    vector<int> vis(n+1, 1e9);
    
    for (auto it : times)
    {
        adj[it[0]].push_back({it[1], it[2]});
    }

    // queue<pair<int, int>> q; // time,node
    priority_queue<
        pair<int,int>, //type of elements stored here(distance,node)
        vector<pair<int,int>>,  //the underllying contatiner used: a vector
        greater<pair<int,int>>   //the comparator: smallest element comes first
    > q;
    q.push({0, k});
    vis[k]=0;


    while (!q.empty())
    {
        auto temp = q.top();
        int node = temp.second;
        int time = temp.first;
        q.pop();

        for (auto it : adj[node])
        {
            int adjNode = it.first;
            int edgeWeight = it.second;
            if (time + edgeWeight < vis[adjNode])
            {
                vis[adjNode] = time + edgeWeight;
                q.push({time + edgeWeight, adjNode});
            }
        }
    }

    int minTime= 0;
    for(int i=1;i<=n;i++){
        minTime=max(minTime, vis[i]);
    }


    if(minTime==1e9)return -1;
    return minTime;
}

int main()
{
    FAST_IO;
    vector<vector<int>> times={{2,1,1},{2,3,1},{3,4,1}};
    cout<<networkDelayTime(times, 4, 2);
    return 0;
}
// by ad73prem