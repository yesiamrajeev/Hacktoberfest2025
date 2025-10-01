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

ListNode* deleteAllOccurences(ListNode* head, int target){
    if(!head)return nullptr; //if empty return empty

    ListNode* dummy = new ListNode(0);
    dummy->next=head;
    head->prev= dummy;

    ListNode* cur= head;
    while(cur){
        if(cur->val== target){
            ListNode* nextNode= cur->next;
            ListNode* prevNode= cur->prev;

            //unlink cur
            if(prevNode){
                prevNode->next= nextNode;
            }
            if(nextNode){
                nextNode->prev= prevNode;
            }

            //free up memory space
            cur->prev= cur->next= nullptr;
            delete cur;

            cur=nextNode;
        }else{
            cur=cur->next;
        }
    }
    ListNode* newhead= dummy->next;
    if(newhead) newhead->prev= nullptr;

    delete dummy;
    return newhead;

}

int main()
{
    FAST_IO;
    ListNode *n1 = new ListNode(1);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(3);
    ListNode *n4 = new ListNode(1); // different node, same value 1
    ListNode *n5 = new ListNode(4);

    // link them: 1 <-> 2 <-> 3 <-> 1 <-> 4
    n1->next = n2;
    n2->prev = n1;
    n2->next = n3;
    n3->prev = n2;
    n3->next = n4;
    n4->prev = n3;
    n4->next = n5;
    n5->prev = n4;

    ListNode *head = n1;
    deleteAllOccurences(n1, 3);
    for (ListNode *cur = head; cur != nullptr; cur = cur->next)
    {
        cout << cur->val;
        if (cur->next)
            cout << " <-> ";
    }
    cout << '\n';
    return 0;
}
//by ad73prem