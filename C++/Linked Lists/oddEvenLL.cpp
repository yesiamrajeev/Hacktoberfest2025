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

ListNode *oddEvenList(ListNode *head)
{
    // we will maintain two seperate linked lists and then join them after the process
    if (head == nullptr)
    {
        return head;
    }
    if (head->next == nullptr)
    {
        return head;
    }
    if (head->next->next == nullptr)
    {
        return head;
    }
    int cnt=1;
    ListNode* temp=head;
    ListNode* odd=head;
    ListNode* even=head->next;
    ListNode* rememberEvenHead= even;
    temp=temp->next->next;
    while(temp!=nullptr){
        if(cnt%2==1){
            odd->next=temp;
            odd=odd->next;
        }else{
            even->next=temp;
            even=even->next;
        }
        temp=temp->next;
        cnt++;
    }
    even->next= nullptr;
    odd->next= rememberEvenHead;
    return head;

}

int main()
{
    FAST_IO;
    
    return 0;
}
//by ad73prem