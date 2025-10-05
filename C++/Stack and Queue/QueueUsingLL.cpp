#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define f(i, a, b) for(int i=a;i<b;i++)
#define all(x) x.begin(),x.end()
#define vprint(v) for (auto& elem : v) cout << elem << " "; cout << endl;
#define vmatprint(vv) for (auto& row : vv) { for (auto& elem : row) cout << elem << " "; cout << endl; } cout << endl;
#define mprint(m) for (auto it : m) cout << it.first << " : " << it.second << endl; cout << endl;
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
    Node* next;

    Node(int data){
        this->data=data;
        this->next=NULL;
    }

};

class MyQueue{
    private:
        Node* top;

    public:
    MyQueue(){
        top=NULL;
    }

    void push(int x){
        Node* newNode= new Node(x);
        newNode->next=top;
        top=newNode;
    }

    void pop(){
        if(top==NULL){
            cout<<"queue empty";
            return;
        }
        if(top->next==NULL){
            top=NULL;
            return;
        }
        Node* temp=top;
        while(temp->next->next!=NULL){
            temp=temp->next;

        }
        temp->next=NULL;
    }


    int back(){
        if(isEmpty()){
            cout<<"queue empty"<<endl;
            return -1;
        }return top->data;
    }

    int front(){
        if(isEmpty()){
            cout<<"queue empty"<<endl;
            return -1;
        }

        Node* temp=top;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        return temp->data;
    }

    bool isEmpty(){
        return top==NULL;
    }

    void display(){
        Node* temp=top;
        if(top==NULL){
            cout<<"stack empty"<<endl;
        }
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
};

int main() {
    FAST_IO;
    MyQueue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.display();
    cout<<endl;
    cout<<q.front()<<endl;
    cout<<q.back()<<endl;
    q.pop();
    q.display();
    return 0;
}
//by ad73prem