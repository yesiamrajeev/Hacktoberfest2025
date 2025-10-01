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

//thso approach we maintin a visited vector of listnode and check if the next node is visited or not

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    vector<ListNode*> visited;
    ListNode* ans;
    while(headA || headB){
        if(headA){
            if(find(visited.begin(), visited.end(), headA)!=visited.end()){
                return headA;
            }
            visited.push_back(headA);
            headA=headA->next;
        }
        if(headB){
            if(find(visited.begin(), visited.end(), headB)!= visited.end()){
                return headB;
            }
            visited.push_back(headB);
            headB=headB->next;
        }
        
    }
    return nullptr;
}


//we can also has the nodes of ll1 and hash it in a map. and then check which node is already in the map.
ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB)
{
    map<ListNode*, int> hash;
    while(headA){
        hash[headA]++;
        headA=headA->next;
    }

    while(headB){
        if(hash.find(headB)!=hash.end()){
            return headB;
        }
        headB=headB->next;
    }
    return nullptr;
}

/*
// now we were storing the nodes. to do this in the runtime we can compare the ndoes direclty while traversing but for that we would want to have the lenghts of the two nodes equal and then traverse one at a time and find the juncture
// head A  : 1-->2-->3-->4--->5--->6-->7
// head B  : 8-->9--->4-> 5-->6-->7

sizeA= 7
sizeb=6

temp: headA
temp2: headB

cnt=1



*/
ListNode * getIntersectionNode3(ListNode* headA, ListNode* headB){
    int sizeA=0; //5
    ListNode* t1= headA;
    while(t1){
        sizeA++;
        t1=t1->next;
    }
    int sizeB = 0; //5
    ListNode *t2 = headB;
    while (t2)
    {
        sizeB++;
        t2 = t2->next;
    }
    ListNode* temp = (sizeA>sizeB)? headA: headB;
    ListNode *temp2 = (sizeA < sizeB) ? headA : headB;
    if(sizeA== sizeB){
        temp= headA;
        temp2= headB;
    }
    int cnt=abs(sizeA-sizeB);
    while(cnt--){
        temp=temp->next;
    } 
    while(temp && temp2){
        if(temp==temp2){
            return temp;
        }
        temp=temp->next;
        temp2=temp2->next;
    }
    
    
    return nullptr;
}

/*
the next and the best approach is to follow the following approach:

we start from the two heads and and traverse both one ndoe at a time. eberytime a mode reaches the last node, that is head->next==nullptr then make it come back to the other head. that way after some iterations they will always come otgether at some pt of time and then meet togetehr at the intersection pt.
*/

ListNode* getIntersectionNodeOpt(ListNode* headA, ListNode* headB){
    if(!headA || !headB)return nullptr;

    ListNode* tempA= headA;
    ListNode* tempB= headB;

    while(tempA!= tempB){
        tempA= (tempA) ? tempA->next: headB;
        tempB=(tempB)? tempB->next: headA;
    }
    return tempA;
}

int main()
{
    FAST_IO;
    ListNode* common= new ListNode(4);
    common->next= new ListNode(5);
    common->next= new ListNode(4);

    ListNode* headA= new ListNode(2);
    headA->next= new ListNode(2);
    headA->next->next= common;

    ListNode *headB = new ListNode(2);
    headB->next = new ListNode(2);
    headB->next->next = common;

    ListNode* inter= getIntersectionNode3(headA, headB);
    cout<<inter->val;
    return 0;
}
//by ad73prem