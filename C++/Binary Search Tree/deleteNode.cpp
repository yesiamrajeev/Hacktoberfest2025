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

TreeNode* deleteNode(TreeNode* root, int key) {
    if(root==NULL){ //what to delete if the tree is only empty
        return NULL;
    }

    if(root->val == key){
        return helper(root);
    }

    TreeNode* dummy= root;
    while(root!= NULL){
        if(root->val > key){
            if(root->left != NULL && root->left->val==key){
                root->left = helper(root->left);
                break;
            }else{
                root=root->left;
            }
        }else{
            if(root->right!= NULL && root->right->val==key){
                root->right =helper(root->right);
                break;
            }else{
                root=root->right;
            }
        }
    }
    return dummy;
}

TreeNode* helper(TreeNode* root){
    if(root->left==NULL){
        return root->right;
    }else if(root->right==NULL){
        return root->left;
    }
    TreeNode* rightChild= root->right;
    TreeNode* lastRight = findLastRight(root->left);
    lastRight->right= rightChild;
    return root->left;

}

TreeNode* findLastRight(TreeNode* root){
    if(root->right==NULL){
        return root;
    }
    return findLastRight(root->right);
}

int main() {
    FAST_IO;
    
    return 0;
}
//by ad73prem