#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f(i, a, b) for (int i = a; i < b; i++)
#define all(x) x.begin(), x.end()
#define vprint(v)            \
    for (auto &elem : v)     \
        cout << elem << " "; \
    cout << endl;
#define vmatprint(vv)            \
    for (auto &row : vv)         \
    {                            \
        for (auto &elem : row)   \
            cout << elem << " "; \
        cout << endl;            \
    }                            \
    cout << endl;
#define mprint(m)                                       \
    for (auto it : m)                                   \
        cout << it.first << " : " << it.second << endl; \
    cout << endl;
#define vint vector<int>
#define vstring vector<string>
#define vmat vector<vector<int>>
#define FAST_IO                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mii map<int, int>
#define mll map<ll, ll>

const int INF = 1e9;
const ll MOD = 1e9 + 7;

void printStack(stack<char> st)
{
    while (!st.empty())
    {
        cout << st.top();
        st.pop();
    }
    cout << endl;
}

string removeKdigits(string num, int k)
{
    // cout<<num.length();
    if (num.length() == k)
    {
        return "0";
    }
    stack<char> st;
    int count = 0;
    for (int i = 0; i < num.length(); i++)
    {
        char ch = num[i];
        while (!st.empty() && st.top() > ch && count < k)
        {
            st.pop();
            count++;
        }
        st.push(ch);

        // cout<<"For i : "<<i<<" and count : "<<count<<endl;
        // printStack(st);
    }

    string ans;
    ll a = 0;
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    reverse(all(ans));

    if (count < k)
    {
        int diff = k - count;
        string answer = ans.substr(0, ans.length() - diff);
        int idx = 0;
        while (idx < answer.length() && answer[idx] == '0')
        {
            idx++;
        }
        answer = answer.substr(idx);
        return answer;
    }
    // cout<<ans;
    // Remove leading zeroes
    int idx = 0;
    while (idx < ans.length() && ans[idx] == '0')
    {
        idx++;
    }
    ans = ans.substr(idx);
    if (ans.empty())
        return "0";
    return ans;

    return to_string(a);
}

int main()
{
    FAST_IO;
    string nums;
    cin >> nums;
    int k;
    cin >> k;
    cout << removeKdigits(nums, k);
    return 0;
}
// by ad73prem