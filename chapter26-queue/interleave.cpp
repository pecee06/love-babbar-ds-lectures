#include <iostream>
#include <stack>
#include <queue>
using namespace std;

void interleave(queue<int>& q){
    stack<int> s;
    int n = q.size();
    for (int i=0; i<n/2; i++){
        s.push(q.front());
        q.pop();
    }
    while (!s.empty()){
        q.push(s.top());
        s.pop();
    }
    for (int i=0; i<n/2; i++){
        q.push(q.front());
        q.pop();
    }
    for (int i=0; i<n/2; i++){
        s.push(q.front());
        q.pop();
    }
    for (int i=0; i<n/2; i++){
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
    }
}

void print(queue<int> q){
    while (!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}

int main()
{
    int n;
    cin>>n;
    (n%2)?exit(0):(void)NULL;

    queue<int> q;
    for (int i=0; i<n; i++){
        int temp;
        cin>>temp;
        q.push(temp);
    }

    interleave(q);
    print(q);

    return 0;
}