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
    ListNode(int x) : val(x), next(NULL) {}
};



ListNode *removeNthFromEnd(ListNode *head, int n)
{
    if(head==nullptr)return head;
    int size=0;
    ListNode* temp= head;
    while(temp!=nullptr){
        size++;
        temp=temp->next;
    }
    // cout<<size<<endl;
    if(size==1){
        if(n<=size){
            return nullptr;
        }
    }
    if(size==2){
        if(n==1){
            head->next=nullptr;
            return head;
        }else if(n==2){
            ListNode* temp=head->next;
            head->next=nullptr;
            delete head;
            return temp;
        }
    }
    // cout<<size<<endl;
    int i= size-n-1;
    // cout<<i<<endl;
    if(i<0){
        ListNode *temp = head->next;
        head->next = nullptr;
        delete head;
        return temp;
    }
    temp=head;
    while(i--){
        temp=temp->next;
    }
    ListNode* nodeDelete=temp->next;
    temp->next=temp->next->next;
    delete nodeDelete;
    return head;


}

ListNode *removeNthFromEnd2(ListNode *head, int n)
{
    ListNode *temp = new ListNode(0); //sometimes head can also be deleted
    temp->next=head;
    ListNode *fast = temp;
    ListNode *slow = temp;

    // firstt we make fast reach n steps ahead
    for (int i = 0; i <= n; i++)
    {
        fast = fast->next;
    }
    // cout<<fast->val<<"$$"<<endl;
    while (fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    // when fast would reach the end slow would absolutely surely reach the node to be deleted
    ListNode *nodeToBeDeleted = slow->next;
    slow->next = slow->next->next;
    delete nodeToBeDeleted;
    return temp->next;
}
int main()
{
    FAST_IO;
    ListNode* head=new ListNode(1);
    head->next=new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    ListNode* ans=removeNthFromEnd2(head,3);
    while(ans){
        cout<<ans->val<<" ";
        ans=ans->next;
    }
    return 0;
}
//by ad73prem