#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void rev(queue<int>& q){
    stack<int> s;
    while (!q.empty()){
        s.push(q.front());
        q.pop();
    }
    while (!s.empty()){
        q.push(s.top());
        s.pop();
    }
}

void rev_recursive(queue<int>& q){
    if (!q.empty()){
        int elem = q.front();
        q.pop();
        rev_recursive(q);
        q.push(elem);
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
    queue<int> q;
    int n, temp;
    cin>>n;
    for (int i=0; i<n; i++){
        cin>>temp;
        q.push(temp);
    }

    // rev(q);
    rev_recursive(q);
    print(q);

    return 0;
}