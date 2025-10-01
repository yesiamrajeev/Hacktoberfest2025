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

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};



int successor(TreeNode* root, int val){
    if (root==nullptr)return -1;
    int succ=INT_MAX;
    while(root!=nullptr){
        if(root->val<val){
            root=root->right;
        }else{
            if(root->val <succ){
                succ=root->val;
            }
            root=root->left;
        }
    }
    return succ;
}

int main() {
    FAST_IO;
    TreeNode* root=new TreeNode(5, new TreeNode(3), new TreeNode(7));
    root->left= new TreeNode(3, new TreeNode(2), new TreeNode(4));
    root->right= new TreeNode(7, new TreeNode(6), new TreeNode(9));
    root->left->left->left= new TreeNode(1);
    root->right->right->right= new TreeNode(10);
    root->right->right->left= new TreeNode(8);
    cout<<successor(root, 8);
    

    return 0;
}
//by ad73prem