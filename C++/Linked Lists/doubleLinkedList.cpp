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

void insertAtHead(Node* &head, int d){
    Node* temp=new Node(d);
    if(head==NULL){
        head=temp;
    }
    else{
        temp->next=head;
        head->prev=temp;
        head=temp;
    }
}

void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void insertAtTail(Node* &tail, int d){
    Node* temp=new Node(d);
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
}

void insertAtPosition(Node* &head, Node* &tail, int d,int position){
    Node* node1=new Node(d);
    Node* temp=head;

    if(position==1){
        insertAtHead(head,d);
    }
    else{
        int cnt=1;
        while(cnt<position-1){
            temp=temp->next;
            cnt++;
        }
        if(temp->next==NULL){
            insertAtTail(tail,d);
        }
        else{
            node1->next=temp->next;
            temp->next->prev=node1;
            temp->next=node1;
            node1->prev=temp;
        }
    }
}

void deleteFromHead(Node* &head){
    Node* temp=head;
    temp->next->prev=NULL;
    temp->next=NULL;
    head=temp->next;
    delete(temp);
}

void deleteFromPosition(Node* &head, int position){
    if(position==1){
        deleteFromHead(head);
    }
    else{
        Node* curr=head;
        Node* prev=NULL;

        int cnt=1;
        while(cnt<position){
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        curr->prev=NULL;
        prev->next=curr->next;
        curr->next=NULL;
        delete(curr);
    }
}



int main() {
    FAST_IO;
    Node* node1=new Node(10);
    Node* head=node1;
    Node* tail=node1;
    insertAtHead(head,20);
    print(head);
    insertAtTail(tail,30);
    print(head);
    insertAtPosition(head,tail,40,2);
    print(head);
    deleteFromHead(head);
    print(head);
    deleteFromPosition(head,1);
    return 0;
}
//by ad73prem