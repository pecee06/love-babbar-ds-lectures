#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void rev(queue<int>& q, int k){
    stack<int> s;
    int n = q.size();
    for (int i=0; i < (n-(n%k)); i++){
        s.push(q.front());
        q.pop();
        if (s.size() == k){
            while (!s.empty()){
                q.push(s.top());
                s.pop();
            }
        }
    }
    for (int i=1; i<k; i++){
        q.push(q.front());
        q.pop();
    }
}

int main()
{
    queue<int> q;
    int n,temp;
    cin>>n;
    for (int i=0; i<n; i++){
        cin>>temp;
        q.push(temp);
    }

    cout<<"Group size : ";
    cin>>n;
    rev(q,n);

    while (!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }

    return 0;
}