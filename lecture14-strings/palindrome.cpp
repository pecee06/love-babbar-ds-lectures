#include <iostream>
using namespace std;

int size(char* str){
    int i=0,len=0;
    while (str[i]!='\0'){
        len++;
        i++;
    }
    return len;
}

bool isPalindrome(char* str){
    char* left = str;
    char* right = str+(size(str)-1);
    while (left!=right){
        if (*left != *right){
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    char word[20];
    cout<<"Enter a word : ";
    cin>>word;

    if (isPalindrome(word)){
        cout<<word<<" is a palindrome\n";
    }
    else{
        cout<<word<<" isn't a palindrome\n";
    }
    
    return 0;
}
