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

struct TreeNode{

    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(){
        val=0;
        left=nullptr;
        right=nullptr;
    }
    TreeNode(int x){
        val=x;
        left=nullptr;
        right=nullptr;
    }
    TreeNode(int x, TreeNode* left, TreeNode* right){
        val=x;
        left=left;
        right=right;
    }
};

TreeNode* insertIntoBTS(TreeNode* root, int key){
    if(root==NULL)return new TreeNode(key);
    TreeNode* temp=root; //making a copy since we need ot return the root

    while(true){
        if(temp->val>key){
            if(temp->left!=NULL)temp=temp->left;

            else{
                temp->left= new TreeNode(key);
                break;
            }
        }
        else{
            if(temp->right!=NULL)temp=temp->right;

            else{
                temp->right= new TreeNode(key);
                break;
            }
        }
    }
    return root;
}

int main() {
    FAST_IO;
    
    return 0;
}
//by ad73prem