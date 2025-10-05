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
    ListNode(int x) : val(x), next(NULL){}
};

//totroise hare methoed (floyd cycle detection): if we run slow with one step and fast with two steps they are bound to meet in case of a cycle before fast or fast->next==nullptr
// thsi si true because since the fast moves one step mroe each time, its bound to catch slow once they enter the track that is the cycle. and if theres no cyucle then fast will reach the end of the loop happily
bool hasCycle(ListNode *head) {
    vector<ListNode*> visited;
    while(head!=nullptr){
        if(find(visited.begin(), visited.end(), head)!= visited.end()){
            return true;
        }
        visited.push_back(head);
        head = head->next;
    }
    return false;
}

bool hasCycle2(ListNode* head){
    ListNode* slow= head;
    ListNode* fast= head;
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
        if (fast == slow)
        {
            fast=head; //when they meet we have to keep sloe there only and then take fast back to the start that is head of the linked list and then start moving them one step at a time. the pt where they meet now will be the start of the loop
            int cnt;
            while(true){
                slow=slow->next;
                fast=fast->next;
                if(slow == fast){
                    return slow;    
                }
            }
        }return nullptr;
}

ListNode *detectCycle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
        {
            fast = head; // when they meet we have to keep sloe there only and then take fast back to the start that is head of the linked list and then start moving them one step at a time. the pt where they meet now will be the start of the loop
            while (true)
            {
                if (slow == fast)
                {
                    return slow;
                }
                slow = slow->next;
                fast = fast->next;
                
            }
        }
        
    }return nullptr;
}

int lenOfLoop(ListNode* head){
    ListNode *slow = head;
    ListNode *fast = head;
    ListNode* start;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
        {
            fast = head;
            while (true)
            {
                if (slow == fast)
                {
                    start= slow;
                    break;
                }
                slow = slow->next;
                fast = fast->next;
            }
        }
    }
    // now we can easily get the start of the loop. if we simply start moving forward from the start and at the point wherre we return back to the start that would give the lentghs
    ListNode* temp=start->next;
    int cnt=1;
    while(temp!=start){
        cnt++;
        temp=temp->next;
    }
    return cnt;
}

int main()
{
    FAST_IO;
    ListNode* head= new ListNode(3);
    head->next= new ListNode(2);
    head->next->next= new ListNode(0);
    head->next->next->next= new ListNode(-4);
    ListNode* temp= head->next;
    head->next->next->next->next= temp;
    cout<<hasCycle2(head);
    return 0;
}
//by ad73prem