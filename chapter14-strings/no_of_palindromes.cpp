#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isPalindrome(string str){
    int n = str.length();
    const char* s = str.c_str();
    for (register int i=0; i<n/2; i++){
        if (*(s+i)!=*(s+n-i-1)){
            return false;
        }
    }
    return true;
}

int noOfPalindromes(string str){
    int n = str.length();
    const char* s = str.c_str();
    vector<string> v;
    string temp;
    for (register int i=0; i<=n; i++){
        if (*(s+i) == ' ' || *(s+i) == '\0'){
            v.push_back(temp);
            temp = "";
            continue;
        }
        temp += *(s+i);
    }
    int count = 0;
    for (auto elem:v){
        if (isPalindrome(elem)){
            count++;
        }
    }
    return count;
}

int main(int argc, char const *argv[])
{
    string str;
    cout<<"Enter a string\n";
    getline(cin,str);

    cout<<"Entered string has "<<noOfPalindromes(str)<<" palindromic words\n";
    
    return 0;
}
