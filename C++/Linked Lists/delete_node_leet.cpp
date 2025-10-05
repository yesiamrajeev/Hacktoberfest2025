#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define push(a) push_back(a)
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

//we need to delete a node without having any access to previous node or the head node.
//'it is given that there is always a next node. so we can do this task by simply copying the data of the next node to our current node and then poining to not the next node but to the node that the next node was pointingt that is next>next node

void deleteNode(ListNode* node) {
    ListNode* nextNode=node;
    nextNode=nextNode->next;
    node->data=nextNode->data;
    node->next=nextNode->next;
}

int main() {
    FAST_IO;
    
    return 0;
}
//by ad73prem