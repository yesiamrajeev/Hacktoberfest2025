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
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode* rev=new ListNode(head->val);
    while(head->next!=nullptr){
        ListNode* copy= new ListNode(head->next->val);
        copy->next=rev;
        rev=copy;
        head=head->next;
    }
    //printing of reverse:
    // ListNode* pr=rev;
    // while(pr!=nullptr){
    //     cout<<pr->val<<" -> ";
    //     pr=pr->next;
    // }
    return rev;
}

ListNode* reverselist(ListNode* head){
    ListNode* prevnode= nullptr;
    ListNode* currnode= head;

    while(currnode!=nullptr){
        ListNode* nextnode = currnode->next;//saving this before only 
        currnode->next= prevnode;
        prevnode=currnode;
        currnode= nextnode;
        
    }
    return prevnode;
}

ListNode* Reverse(ListNode* curr, ListNode* prev){

    if(curr==nullptr){
        return prev;
    }
    ListNode* nextNode= curr->next;
    curr->next=prev;
    return Reverse(nextNode, curr);

}

ListNode *reverselistRec(ListNode *head)
{
    return Reverse(head, nullptr);
    // return head;
}

int main() {
    FAST_IO;
    ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    ListNode* temp= reverselistRec(head);
    while(temp!=nullptr){
        cout<<temp->val<<" ";
    }
    return 0;
}
//by ad73prem