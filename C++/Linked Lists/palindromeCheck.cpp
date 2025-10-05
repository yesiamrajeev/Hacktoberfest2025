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

// the msot obv way is to make a vector of all elements if the ll and then check for paliomdrom propoerties. but that woul ebe ineficient. 

// what we willl try to do is find the mid point of the ll and then reverse the 2nd partof the ll in place and then soimple compare node by node both the first half and the second half

bool isPalindrome(ListNode *head)
{
    //finding the midpoint with tortoise and rabbit approach
    ListNode* slow=head;
    ListNode* fast=head;

    while(fast->next && fast->next->next){
        slow=slow->next;
        fast=fast->next->next;
    }

    //now we know that the slow node is the middle node. now we need to reverse the 2nd part of the ll

    ListNode* curr= slow->next;
    ListNode* prev= nullptr;
    if(slow->next==nullptr){
        if(slow->val==head->val)return true;
        return false;
    }
    // cout<<"middle: "<<slow->val<<endl;
    while(curr!= nullptr){
        ListNode* nextNode= curr->next;
        curr->next= prev;
        prev= curr;
        curr= nextNode;
    }
    // now the 2nd part of the loop is reversed

    ListNode* node1= head;
    ListNode* node2= prev;
    // cout<<"node1: "<<node1->val<<endl;
    // cout << "node2: " << node2->val<<endl;

    //comparing the two halves
    while(node2){ //since node 2 will always be the shorter half
        if(node1->val!=node2->val){
            return false;
        }
        node1=node1->next;
        node2=node2->next;
    }
    return true;
}

bool isPalindromeCheck(ListNode* head){
    vector<int> nums;
    while(head!=nullptr){
        nums.push_back(head->val);
        head=head->next;
    }
    vector<int> temp=nums;
    reverse(temp.begin(), temp.end());
    if(temp==nums){
        return true;
    }return false;
}
// 1,1,2,1
int main()
{
    FAST_IO;
    ListNode* head=new ListNode(1);
    head->next= new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);
    cout << isPalindrome(head);
    return 0;
}
//by ad73prem