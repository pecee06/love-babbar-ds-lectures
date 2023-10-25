// Problem statement: Given a string, for example "the sky is blue" you have to reverse it like "blue is sky the"

#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

void reverseWords(string& str){
    stack<char> s;
    string temp;
    int n = str.length(), i;
    for (i=0; i<=n; i++){
        if (str[i]==' ' || str[i]=='\0'){
            while (!s.empty()){
                temp += s.top();
                s.pop();
            }
            temp += ' ';
        }
        else{
            s.push(str[i]);
        }
    }
    temp.pop_back();
    reverse(temp.begin(), temp.end());
    str = temp;
}

int main(int argc, char const *argv[])
{
    string str;
    cout<<"Enter a string\n";
    getline(cin,str);
    reverseWords(str);
    cout<<"String with reversed words\n"<<str<<endl;
    
    return 0;
}