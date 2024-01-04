#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    string str;
    getline(cin,str);

    stack<char> s;
    for (auto elem:str)
        s.push(elem);
    str.clear();
    while (!s.empty()){
        str += s.top();
        s.pop();
    }
    cout<<str<<endl;

    return 0;
}