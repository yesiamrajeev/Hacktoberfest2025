#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define f(i, a, b) for(int i=a;i<b;i++)
#define all(x) x.begin(),x.end()
#define vprint(v) for (auto& elem : v) cout << elem << " "; cout << endl;
#define vmatprint(vv) for (auto& row : vv) { for (auto& elem : row) cout << elem << " "; cout << endl; } cout << endl;
#define mprint(m) for (auto it : m) cout << it.first << " : " << it.second << endl; cout << endl;
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

int largestRectangleArea(vector<int> &heights)
{
    stack<int> st;
    int maxArea = 0;
    int n = heights.size();
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && heights[st.top()] > heights[i])
        {
            int idx = st.top();
            st.pop();
            int nse = i;
            int pse = st.empty() ? -1 : st.top();
            maxArea = max(heights[idx] * (nse - pse - 1), maxArea);
        }
        st.push(i);
    }

    while (!st.empty())
    {
        int idx = st.top();
        st.pop();
        int nse = n;
        int pse = st.empty() ? -1 : st.top();
        maxArea = max(heights[idx] * (nse - pse - 1), maxArea);
    }

    return maxArea;
}

int maximalRectangle(vector<vector<char>>& matrix) {
    int m=matrix.size();//number of rows

    int n= m==0? 0:matrix[0].size();//number of columns
    // cout<<n<<m; 
    vmat prefixSum(m, vector<int>(n, 0));
    for(int j=0;j<n;j++){
        int sum=0;
        for(int i=0;i<m;i++){
            if(matrix[i][j]=='0'){
                sum=0;
            }

            sum+=matrix[i][j]-'0';
            prefixSum[i][j]=sum;

        }
    }
    // vmatprint(prefixSum);
    int maxArea=0;
    for(int i=0;i<m;i++){
        maxArea=max(maxArea,largestRectangleArea(prefixSum[i]));
    }
    return maxArea;
}

int main() {
    FAST_IO;
    vector<vector<char>> mat={
    {'1'}
};
    cout<<maximalRectangle(mat);
    return 0;
}
//by ad73prem