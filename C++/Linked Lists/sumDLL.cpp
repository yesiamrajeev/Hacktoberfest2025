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

struct ListNode
{
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode()
    {
        val = 0;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode *prev1)
    {
        val = data1;
        next = next1;
        prev = prev1;
    }
};

vector<vector<int>> findPairsWithGivenSum(ListNode* head, int target){
    ListNode* s= head;
    ListNode* e= head;
    while(e->next){
        e=e->next;
    }
    vector<vector<int>> ans;
    while(s->val<=e->val){
        int sum=s->val+e->val;
        if(sum<target){
            s=s->next;
        }else if(sum>target){
            e=e->prev;
        }else{
            ans.push_back({s->val, e->val});
            s=s->next;
            e=e->prev;
        }
    }
    return ans;
}

int main() {
    FAST_IO;
    ListNode* head = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(4);
    ListNode* node4 = new ListNode(5);
    ListNode* node5 = new ListNode(6);
    ListNode* node6 = new ListNode(8);
    ListNode* node7 = new ListNode(9);

    head->next = node2;
    node2->prev = head;
    node2->next = node3;
    node3->prev = node2;
    node3->next = node4;
    node4->prev = node3;
    node4->next = node5;
    node5->prev = node4;
    node5->next = node6;
    node6->prev = node5;
    node6->next = node7;
    node7->prev = node6;
    vector<vector<int>> res= findPairsWithGivenSum(head, 7);
    for (auto &pair : res) {
        cout << pair[0] << " " << pair[1] << endl;
    }
    return 0;
}
//by ad73prem