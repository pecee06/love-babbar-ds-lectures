#include <iostream>
#include <string>
#include <deque>
using namespace std;

string f(string stream){
    deque<char> q;
    for (auto elem:stream){
        if (!q.empty() && elem == q.front()) q.push_front('#');
        else{
            if (q.empty() || q.front() == '#') q.push_front(elem);
            else q.push_front(q.front());
        }
    }
    string s = "";
    while (!q.empty()){
        s += q.back();
        q.pop_back();
    }
    return s;
}

int main()
{
    string stream;
    cin>>stream;

    string solution = f(stream);
    cout<<solution<<endl;

    return 0;
}