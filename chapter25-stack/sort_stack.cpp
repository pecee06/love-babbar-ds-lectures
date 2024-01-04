#include <iostream>
#include <stack>
using namespace std;

void sortedInsert(stack<int>& s, int x){
    if (x >= s.top()){
        s.push(x);
        return;
    }
    int elem = s.top();
    s.pop();
    sortedInsert(s,x);
    s.push(elem);
}

void sort(stack<int>& s){
    if (!s.empty()){
        int elem = s.top();
        s.pop();
        sort(s);
        if (!s.empty()) sortedInsert(s,elem);
        else s.push(elem);
    }
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

    int n, temp;
    cin>>n;
    for (int i=0; i<n; i++){
        cin>>temp;
        s.push(temp);
    }

    sort(s);
    print(s);

    return 0;
}