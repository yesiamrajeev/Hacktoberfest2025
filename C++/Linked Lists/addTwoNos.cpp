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
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr){} 
    ListNode(int x, ListNode *next) : val(x), next(next){}                                                                                                                                 
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode* ans= new ListNode(0);
    ListNode* temp= ans;
    int c=0;
    while(l1 && l2){
        // cout<<l1->val<<" "<<l2->val<<endl;
        int x= l1->val + l2->val + c;
        // cout<<"x : "<<x<<endl;
        int d= x%10;
        // cout<<"d : "<<d<<endl;
        c= x/10;
        // cout<<"c : "<<c<<endl;
        ans->next= new ListNode(d);
        // cout<<"ans->val : "<<ans->next->val<<endl;
        ans=ans->next;
        l1=l1->next;
        l2=l2->next;
    }
    while(l1){
        // cout<<"hello"<<endl;
        int x=l1->val+c;
        int d=x%10;
        c=x/10;
        ans->next= new ListNode(d);
        ans= ans->next;
        l1=l1->next;
    }
    while (l2)
    {
        // cout << "hello" << endl;
        int x = l2->val + c;
        int d = x % 10;
        c = x / 10;
        ans->next = new ListNode(d);
        ans = ans->next;
        l2 = l2->next;
    }
    // while (ans)
    // {
    //     cout << ans->val << "-->";
    //     ans = ans->next;
    // }
    return temp->next;
}

int main()
{
    FAST_IO;
    ListNode* l1= new ListNode(2);
    l1->next= new ListNode(4);
    l1->next->next= new ListNode(3);
    ListNode* l2= new ListNode(5);
    l2->next= new ListNode(6);
    l2->next->next= new ListNode(4);
    ListNode* ans= addTwoNumbers(l1, l2);
    while(ans){
        cout<<ans->val<<"-->";
        ans=ans->next;
    }
    return 0;
}
//by ad73prem