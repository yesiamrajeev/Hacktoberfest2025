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
#define stackprint(st) while(!(st).empty()) { cout<<(st).top()<<" "; (st).pop(); } cout<<endl;

const int INF = 1e9;
const ll MOD = 1e9+7;

void printStack(stack <int> st){
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}

vector<int> asteroidCollision(vector<int>& asteroids) {
    int n=asteroids.size();
    stack<int> st;
    for(int i=0;i<n;i++){
        bool flag=true;
        while(!st.empty()&&st.top()*asteroids[i]<0&&(st.top()>0&&asteroids[i]<0)){
            // cout<<"hello";
            if(abs(st.top())<abs(asteroids[i])){
                st.pop();
            }
            else if(abs(st.top())==abs(asteroids[i])){
                st.pop();
                flag=false;
                break;
            }
            else{
                flag=false;
                break;
            }
        }
        if(flag==true){
            st.push(asteroids[i]);
        }


        // cout<<"i : "<<i<<" current stack is : ";
        // printStack(st);
    }

    vint ans;
    while(!st.empty()){
        // cout<<st.top()<<endl;
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main() {
    FAST_IO;
    vint ast={-2,1,1,-1};
    vint ans=asteroidCollision(ast);
    vprint(ans);
    return 0;
}
//by ad73prem