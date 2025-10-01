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

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
void insertAtPosition(Node *&head, int pos, int x)
{
    Node *newNode = new Node(x);
    if (pos == 0 || pos == 1)
    {
        newNode->next = head;
        head = newNode;
        return;
    }
    else
    {
        Node *temp = head;
        int cnt = 1;
        while (cnt < pos - 1 && temp != NULL)
        {
            temp = temp->next;
            cnt++;
        }

        if (temp == NULL)
        {
            cout << "Position out of bounds" << endl;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}
void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {

        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << endl;
}

void deleteAtPosition(Node *&head, int pos)
{
    if (pos == 1)
    {
        head = head->next;
        return;
    }
    Node *curr = head;
    Node *prev = NULL;
    int cnt = 1;
    while (cnt < pos)
    {
        prev = curr;
        curr = curr->next;
        cnt++;
    }
    prev->next = curr->next;
    curr->next = NULL;
}

class MyStack
{
public:
    Node *n1;

    void push(int x)
    {
        insertAtPosition(n1,size(n1),x);
    }

    void size(Noden1){
        int cnt=0;

    }
};

int main()
{
    FAST_IO;
    Node *head = new Node(2);
    insertAtPosition(head, 0, 4);
    insertAtPosition(head, 1, 6);
    insertAtPosition(head, 0, 8);
    print(head);
    insertAtPosition(head, 7, 10);
    deleteAtPosition(head, 2);
    print(head);
    return 0;
}
// by ad73prem