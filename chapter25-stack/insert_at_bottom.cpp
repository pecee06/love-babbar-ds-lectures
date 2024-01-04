// Problem: Given a stack already containing some elements. Insert an element at bottom of stack

#include <iostream>
#include <stack>
using namespace std;

void insert(stack<int>& s, int x){
    if (s.empty()){
        s.push(x);
        return;
    }
    int elem = s.top();
    s.pop();
    insert(s,x);
    s.push(elem);
}

void print(stack<int> s){
    while (!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    int x;
    cin>>x;
    insert(s,x);
    print(s);

    return 0;
}