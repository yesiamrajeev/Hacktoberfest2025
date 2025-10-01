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

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    //constructor
    Node(int d){
        this->data=d;
        this->prev=NULL;
        this->next=NULL;
    }

    //deconstructor
    ~Node(){
        int val=this->data;
        if(next!=NULL){
            delete next;
            next=NULL;
        }
        cout<<"memeory has been freed from value : "<<val<<endl;
    }
};

Node *addNode(Node *head, int pos, int data) {
    Node* temp=head;
    Node* node1=new Node(data);
    if(pos==1){
        node1->next=head;
        head->prev=node1;
        node1->prev=NULL;
        node1=head;
    }
    else{
        int cnt=1;
        while(cnt<pos-1){
            temp=temp->next;
            cnt++;
        }
        node1->next=temp->next;
        temp->next->prev=node1;
        temp->next=node1;
        node1->prev=temp;
        
    }
    return head;

}

int main() {
    FAST_IO;
    
    return 0;
}
//by ad73prem