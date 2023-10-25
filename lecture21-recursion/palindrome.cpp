#include <iostream>
#include <string>
using namespace std;

bool isPalindromeHelper(string str, int from, int to){
    if (from>=to){
        return true;
    }

    if (str[from] == str[to]){
        return isPalindromeHelper(str,from+1,to-1);
    }
    return false;
}

bool isPalindrome(string str){
    return isPalindromeHelper(str,0,str.length()-1);
}

int main(int argc, char const *argv[])
{
    string s;
    cout<<"Enter a word : ";
    cin>>s;

    if (isPalindrome(s)){
        cout<<s<<" is a palindrome\n";
    }
    else{
        cout<<s<<" isn't a palindrome\n";
    }

    return 0;
}