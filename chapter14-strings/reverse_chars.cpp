// Problem statement: Given a string "hello world" (say), you have to reverse it like "olleh dlrow"

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string reverse(string& str){
    int n = str.length();
    for (register int i=0; i<n/2; i++){
        swap(str[i],str[n-i-1]);
    }
    return str;
}

void reverseChars(string& str){
    vector<string> v;
    string temp;
    int n = str.length();
    for (register int i=0; i<=n; i++){
        if (str[i]==' ' || str[i]=='\0'){
            v.push_back(temp);
            temp = "";
        }
        else{
            temp += str[i];
        }
    }
    str.clear();
    for (auto elem:v){
        str+=reverse(elem)+' ';
    }
    str.pop_back();
}

int main(int argc, char const *argv[])
{
    string str;
    cout<<"Enter a string\n";
    getline(cin,str);
    reverseChars(str);
    cout<<"String with reversed characters\n"<<str<<endl;
    
    return 0;
}
