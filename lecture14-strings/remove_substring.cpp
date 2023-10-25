// Problem statement: Given a string of words and a word, remove all occurences of the word from the original string

#include <iostream>
#include <string>
#include <climits>
using namespace std;

void removeSubStr(string& str, string& substr){
    static int pos = 0;
    pos = str.find(substr,pos);
    str.erase(pos,substr.length());
    if (str.find(substr,pos) > INT_MAX){
        return;
    }
    removeSubStr(str,substr);
}

int main(int argc, char const *argv[])
{
    string str,part;
    cout<<"Enter a string\n";
    getline(cin,str);
    cout<<"Enter a substring, to remove from the string\n";
    getline(cin,part);
    removeSubStr(str,part);
    cout<<"New string : "<<str<<endl;
    
    return 0;
}
