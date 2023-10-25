#include <iostream>
#include <string>
using namespace std;

string revHelper(string str, int from, int to){
    if (from>=to){
        return str;
    }
    swap(str[from],str[to]);
    return revHelper(str,from+1,to-1);
}

string rev(string str){
    return revHelper(str,0,str.length()-1);
}

int main(int argc, char const *argv[])
{
    string s;
    cout<<"Enter a word : ";
    cin>>s;

    string str = rev(s);
    cout<<"Reversed string\n"<<str;

    return 0;
}