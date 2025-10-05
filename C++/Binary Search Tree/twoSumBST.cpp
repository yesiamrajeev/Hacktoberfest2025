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

void pushAllLeft(TreeNode* node, stack<TreeNode*> &st){
    while(node){
        st.push(node);
        node=node->left;
    }
}

void pushAllRight(TreeNode* node, stack<TreeNode*> &st){
    while(node){
        st.push(node);
        node=node->right;
    }
}


bool findTarget(TreeNode* root, int k) {
    stack<TreeNode*> st1;
    stack<TreeNode*> st2;
    pushAllLeft(root, st1); //smallest
    pushAllRight(root, st2); //largest
    while(!st1.empty() && !st2.empty() && st1.top()!=st2.top()){
        int sum=st1.top()->val + st2.top()->val;
        if(sum == k)return true;

        else if(sum<k){
            TreeNode* node=st1.top();
            st1.pop();
            pushAllLeft(node->right, st1);
        }

        else{
            TreeNode* node= st2.top();
            st2.pop();
            pushAllRight(node->left, st2);
        }
    }
    return false;
}

int main() {
    FAST_IO;
    TreeNode* root= node(5, node(3, node(2) , node(4)), node(6,nullptr,node(7)));
    cout<<findTarget(root, 5);
    return 0;
}
//by ad73prem