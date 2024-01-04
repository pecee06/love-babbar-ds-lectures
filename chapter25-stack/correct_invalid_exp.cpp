// Problem: Given an expression containing only '{' or '}'. In case parenthesis aren't balanced, return the minimum number of changes ('{' to '}' or vice versa) needed to make it valid

#include <iostream>
#include <stack>
using namespace std;

int changesToMakeValid(string exp){
    int a = 0, b = 0, n = exp.length();
    stack<char> s;
    if (!(n%2)){
        int invalidClosing = 0;
        for (auto elem:exp){
            if (elem == '{') s.push(elem);
            else{
                if (s.empty()) invalidClosing++;
                else s.pop();
            }
        }
        int invalidOpening = s.size();
        int totalInvalidChars = invalidOpening+invalidClosing;
        if (invalidOpening == totalInvalidChars || invalidClosing == totalInvalidChars) return invalidOpening;
        return (invalidOpening+1)/2 + (invalidClosing+1)/2;
    }
    return -1;
}

int main()
{
    string exp;
    cin>>exp;

    cout<<"We need to make "<<changesToMakeValid(exp)<<" changes\n";

    return 0;
}