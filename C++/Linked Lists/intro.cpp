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

//creating a class of Node. Just like creaing a data structure
class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this ->data=data;
        this ->next=NULL;
    }
};

void insertAtHead(Node* &head,int d){
    Node* temp=new Node(d);
    temp->next=head;
    head=temp;
}

void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void insertAtTail(Node* &tail,int d){
    Node* temp=new Node(d);
    tail->next=temp;
    tail=temp;
}

void insertAtPosition(Node* head,Node* tail, int position, int d){
    if(position==1){
        insertAtHead(head,d);
        return;
    }
    
    Node * temp=head;
    int cnt=1;
    while(cnt<position-1){
        temp=temp->next;
        cnt++;
    }
    if(temp->next==NULL){
        insertAtTail(tail,d);
        return;
    }
    Node* nodeToInsert =new Node(d);
    nodeToInsert->next=temp->next;
    temp->next=nodeToInsert;

    
}

int main() {
    FAST_IO;
    Node* node1=new Node(10);
    Node* head=node1;
    Node* tail=node1;
    insertAtTail(tail,15);
    insertAtTail(tail,22);
    insertAtPosition(head,tail,4,30);
    print(head);
    return 0;
}
//by ad73prem