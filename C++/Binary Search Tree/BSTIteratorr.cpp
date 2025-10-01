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

TreeNode* node(int val, TreeNode* left=nullptr, TreeNode* right=nullptr) {
    return new TreeNode(val, left, right);
}


class BSTIterator {

    stack<TreeNode*> st;
public:

    BSTIterator(TreeNode* root) {
        while(root!=nullptr){
            st.push(root);
            root=root->left;
        }
    }
    
    int next() {
        TreeNode* node= st.top();
        int ans=node->val;
        st.pop();
        if(node->right!=nullptr){
            node=node->right;
            while(node!=nullptr){
                st.push(node);
                node=node->right;
            }
        }
        return ans;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

int main() {
    FAST_IO;
    TreeNode*  root=node(7, node(3, node(2, node(1)), node(6, node(5, node(4)))), node(10, node(9, node(8))));
    BSTIterator(root);

    return 0;
}
//by ad73prem