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

class Node {
    public:
        int data;
        Node* next;
    
        Node(int data) {
            this->data = data;
            this->next = NULL;
        }
    };
    

class MyStack{
    private:
        Node* top;

    public:
        MyStack() {
            top=NULL;
        }   //initialize empty stack

        void push(int x){
            Node* newNode =  new Node(x);
            newNode->next=top;
            top=newNode;
        }

        void pop(){
            if(isEmpty()){
                cout<<"stack underflow"<<endl;
                return;
            }

            Node* temp=top;
            top=top->next;
            delete temp;
        }

        int peek(){
            if(isEmpty()){
                cout<<"stack underflow"<<endl;
                return -1;
            }
            return top->data;
        }

        bool isEmpty(){
            return top==NULL;
        }
    

        void display(){
            Node*temp=top;

            while(temp!=NULL){
                cout<<temp->data<<" ";
                temp=temp->next;
            }
            cout<<endl; 
        }

        ~MyStack(){
            while(!isEmpty()){
                pop();
            }
        }
        
};

int main() {
    FAST_IO;
    MyStack s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout<<"top element : "<<s.peek()<<endl;
    s.display();
    s.pop();
    s.display();
    return 0;
}
//by ad73prem