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

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    ListNode* t1= list1;
    ListNode* t2= list2;
    ListNode* dummy = new ListNode(0);
    ListNode* ans= dummy;

    while(t1 && t2){
        if(t1->val<=t2->val){
            ans->next= t1;
            t1=t1->next;
        }else{
            ans->next= t2;
            t2=t2->next;
        }
        ans=ans->next;
    }
    ans->next= (t1)? t1:t2;
    return dummy->next;
}

int main()
{
    FAST_IO;
    ListNode* arr=new ListNode(1, new ListNode(2, new ListNode(4)));
    ListNode* arr2= new ListNode(1, new ListNode(3, new ListNode(4)));
    ListNode* answer= mergeTwoLists(arr, arr2);
    while(answer){
        cout<<answer->val<<" ";
        answer= answer->next;
    }
    return 0;
}
//by ad73prem