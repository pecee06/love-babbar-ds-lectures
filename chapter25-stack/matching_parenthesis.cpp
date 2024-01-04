#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool parenthesisBalanced(string& exp){
    stack<char> s;
    for (auto elem:exp){
        if (elem == '(' || elem == '{' || elem == '[')
            s.push(elem);
        else if (elem == ')'){
            if (s.top() != '(') return false;
            s.pop();
        }
        else if (elem == '}'){
            if (s.top() != '{') return false;
            s.pop();
        }
        else if (elem == ']'){
            if (s.top() != '[') return false;
            s.pop();
        }
    }
    if (s.empty()) return true;
    return false;
}

int main()
{
    string exp;
    cin>>exp;
    if (parenthesisBalanced(exp))
        cout<<"Parenthesis is balanced\n";
    else cout<<"Parenthesis ain't balanced\n";

    return 0;
}