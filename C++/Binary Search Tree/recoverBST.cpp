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

//the intuition is to find the two swapped nodes since they mustt be breaking the order oof the treee and then swap them brutely

void inOrderTraversal(TreeNode* root, vector<TreeNode*>& inOrder){
    if(root==nullptr)return;

    inOrderTraversal(root->left, inOrder);
    inOrder.push_back(root);
    inOrderTraversal(root->right, inOrder);
}

void recoverTree(TreeNode* root) {
    //first we will perform an inorder traversal on the tree
    vector<TreeNode*> inOrder;
    inOrderTraversal(root, inOrder);
    vector<TreeNode*> defects;
    for(int i=0;i<inOrder.size()-1;i++){
        if(inOrder[i]->val>inOrder[i+1]->val){
            defects.push_back(inOrder[i]);
            defects.push_back(inOrder[i+1]);
        }
    }
    if(defects.size()==2){
        swap(defects[0]->val, defects[1]->val);
    }
    else{
        swap(defects[0]->val, defects[3]->val);
    }
}

int main() {
    FAST_IO;
    TreeNode* root= node(1, node(3, nullptr, node(2)), nullptr);
    recoverTree(root);
    return 0;
}
//by ad73prem