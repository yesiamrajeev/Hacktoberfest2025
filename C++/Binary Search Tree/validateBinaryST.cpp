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

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool checkBST(TreeNode* root, long long low, long long high){
    if(root->val<=low || root->val>=high)return false;
    bool b1=true, b2=true;
    if(root->left){
        b1= checkBST(root->left, low, root->val);
    }

    if(root->right){
        b2= checkBST(root->right, root->val, high);
    }

    return b1 && b2;
}

bool isValidBST(TreeNode *root)
{
    long long low=LLONG_MIN;
    long long high= LLONG_MAX;
    return checkBST(root, low, high);
}

int main()
{
    FAST_IO;

    return 0;
}
// by ad73prem