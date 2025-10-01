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

class Queue{
    public:
        int *arr;
        int front;
        int back;
        int size;

    Queue(int size){
        this->size=size;
        arr=new int[size];
        front=0;
        back=-1;
    }

    void push(int n){
        if(size>back+1){
            back++;
            arr[back]=n;
        }
        else{
            cout<<"queue overflow"<<endl;
        }
    }
    

    void pop(){
        if(front<=back){
            front++;
        }
        else{
            cout<<"queue underflow"<<endl;
        }
    }

    int Size(){
        return size;
    }

    bool isempty(){
        if(front>back){
            return true;
        }return false;
    }

    int Front(){

        if(front<=back){
            return arr[front];
        }
        else{
            cout<<"stack is empty"<<endl;
            return -1;
        }
        
    }

    int Back(){
        if(front<=back){
            return arr[back];
        }
        else{
            cout<<"stack is empty"<<endl;
            return -1;
        }
    }
};



int main() {
    FAST_IO;
    Queue q=Queue(5);
    cout<<q.Size()<<endl;
    q.push(10);
    q.push(20);
    q.push(30);
    q.pop();
    q.pop();
    q.pop(); 
    cout<<q.isempty()<<endl;
    cout<<q.Front()<<endl;
    cout<<q.Back()<<endl;
    return 0;
}
//by ad73prem