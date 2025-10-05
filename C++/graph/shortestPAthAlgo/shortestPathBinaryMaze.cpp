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

int shortestPathBinaryMatrix(vector<vector<int>> &grid)
{
    int n = grid.size();
    if(grid[0][0]==1 || grid[n-1][n-1]==1)return -1; //check if the start and end are blocked or something
    vector<vector<int>> distance(n, vector<int>(n, 1e9));
    queue<pair<int, pair<int, int>>> q; //{dist,{row,col}}
    q.push({0, {0, 0}});                // starting node
    distance[0][0]=0;
    vector<int> drow = {-1, -1, -1, 0, 1, 1, 1, 0};
    vector<int> dcol = {-1, 0, 1, 1, 1, 0, -1, -1};
    while (!q.empty())
    {
        auto node = q.front();
        int dist = node.first;
        int r = node.second.first;
        int c = node.second.second;
        q.pop();

        for (int i = 0; i < 8; i++)
        {
            int nrow = r + drow[i];
            int ncol = c + dcol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && grid[nrow][ncol] == 0 && distance[nrow][ncol]>dist+1)
            {
                q.push({dist+1,{nrow,ncol}});
                distance[nrow][ncol]=dist+1;
            }
        }
    }
    if(distance[n-1][n-1]==1e9){
        return -1;
    }
    return distance[n-1][n-1]+1;
}

int main()
{
    FAST_IO;
    vector<vector<int>> grid={{0,0,0},{1,1,0},{1,1,0}};
    cout<<shortestPathBinaryMatrix(grid);
    return 0;
}
// by ad73prem