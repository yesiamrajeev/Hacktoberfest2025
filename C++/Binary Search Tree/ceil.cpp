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

int ceilFind(TreeNode* root, int key){
    int ceil=-1;
    while(root!=NULL){
        if(root->val==key)return key;

        if(root->val<key){
            root=root->right;
        }
        else{
            ceil=root->val;
            root=root->left;
        }
    }
    return ceil;
}
int floorFind(TreeNode* root, int key){
    int floor=-1;
    while(root!=NULL){
        if(root->val==key)return key;

        if(root->val>key){
            root=root->left;
        }

        else{
            floor= root->val;
            root=root->right;
        }
    }
    return floor;
}

int main() {
    FAST_IO;
    TreeNode* root= new TreeNode(10);
    root->left=new TreeNode(5);
    root->right=new TreeNode(13);
    root->left->left= new TreeNode(3);
    root->left->right= new TreeNode(6);
    root->right->left= new TreeNode(11);
    root->right->right= new TreeNode(14);
    root->left->left->left= new TreeNode(2);
    root->left->left->right= new TreeNode(4);
    root->left->right->right= new TreeNode(9);
    cout<<floorFind(root, 8);
    return 0;
}
//by ad73prem