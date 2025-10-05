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

// we will sort an ll containing only 0,1 and 2s while reconnecting the nodes

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// 0->1->0->1->2->0
ListNode* sorted(ListNode* head){
    ListNode* zero= new ListNode(0);
    ListNode* ones= new ListNode(0);
    ListNode* twos= new ListNode(0);

    ListNode* ptr0=zero;
    ListNode* ptr1=ones;
    ListNode* ptr2=twos;

    while(head){
        if(head->val== 0){
            ptr0->next=head;
            ptr0=ptr0->next;
        }
        if(head->val==1){
            ptr1->next= head;
            ptr1=ptr1->next;
        }
        if(head->val==2){
            ptr2->next=head;
            ptr2= ptr2->next;
        }
        // cout<<"head -> val : "<<head->val<<endl;
        // cout<<"ptr0 -> val : "<<ptr0->val<<endl;
        // cout<<"ptr1 -> val : "<<ptr1->val<<endl;
        // cout<<"ptr2 -> val : "<<ptr2->val<<endl;
        head = head->next;
    }
    ptr0->next=ones->next;
    ptr1->next=twos->next;
    ptr2->next= nullptr;
    // while(zero){
    //     cout<<zero->val<<"->";
    //     zero=zero->next;
    // }
    return zero->next;
}

int main() {
    FAST_IO;
    ListNode* head= new ListNode(0, new ListNode(1, new ListNode(0, new ListNode(1, new ListNode(2, new ListNode(0))))));
    ListNode* ans = sorted(head);
    // sorted(head);
    while(ans){
        cout<<ans->val<<"-->";
        ans=ans->next;
    }
    return 0;
}
//by ad73prem