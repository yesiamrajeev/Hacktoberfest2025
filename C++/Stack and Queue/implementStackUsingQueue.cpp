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


class Mystack{
    private:
        queue <int> q1;
        queue <int> q2;

    public:
        Mystack(){}

        void Push(int x){

            q1.push(x);
        }

        int Pop(){
            while(q1.size()!=1){
                q2.push(q1.front());
                q1.pop();
            }
            int result=q1.front();
            q1.pop();
            swap(q1,q2);
            return result;
            
        }

        int top(){
            return q1.back();
        }

        bool empty(){
            if(q1.empty()){
                return true;
            }return false;
            
        }

};


int main() {
    FAST_IO;
    Mystack m;
    m.Push(2);
    m.Push(4);
    m.Push(6);
    cout<<m.top()<<endl;
    m.Pop();
    cout<<m.top();
    return 0;
}
//by ad73prem