// Given a valid mathematical expression in string format that can contain '(', ')', operators and lowercase alphabets, check whether it has redundant brackets

#include <iostream>
#include <stack>
using namespace std;

bool isOperator(char c){
    char operators[] = {'+','-','*','/','%'};
    int n = sizeof(operators)/sizeof(char);
    for (int i=0; i<n; i++)
        if (c == operators[i]) return true;
    return false;
}

bool redundancy(string exp){
    stack<char> s;
    for (auto elem:exp){
        if (elem == '(' || isOperator(elem))
            s.push(elem);
        else if (elem == ')'){
            bool operatorInBetween = false;
            while (s.top() != '('){
                if (isOperator(s.top())) operatorInBetween = true;
                s.pop();
            }
            if (!operatorInBetween) return true;
            s.pop();
        }
    }
    return false;
}

int main()
{
    string exp;
    cin>>exp;

    if (redundancy(exp))
        cout<<"Expression has redundant brackets\n";
    else cout<<"Expression doesn't have redundant brackets\n";

    return 0;
}