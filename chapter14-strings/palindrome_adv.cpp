// Problem statement: Given a string which may contain uppercase letters, spaces & special characters (including numeric characters) as well. You have to find whether it's palindrome or not, by treating uppercase & lowercase letters as same and neglecting spaces & special characters

#include <iostream>
#include <cmath>
using namespace std;

int size(char* str){
    int i=0,len=0;
    while (str[i]!='\0'){
        len++;
        i++;
    }
    return len;
}

bool isAlphabet(char c){
    int ascii = (int)c;
    bool cond1 = ascii>= 65 && ascii<= 90;
    bool cond2 = ascii>= 97 && ascii<= 122;
    if (cond1||cond2){
        return true;
    }
    return false;
}

bool isPalindrome(char* str){
    char* left = str;
    char* right = str+(size(str)-1);
    while (left<right){
        if (*left != *right){
            if (!isAlphabet(*left)){
                left++;
                continue;
            }
            if (!isAlphabet(*right)){
                right--;
                continue;
            }

            if (abs(*left-*right)==32){
                left++;
                right--;
            }
            else{
                return false;
            }
        }
        left++;
        right--;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    // char str[30] = "aBc *-/-gfggfg6 74cba";
    char str[30] = "abc *-/-gfggfg6 z74cba";

    if (isPalindrome(str)){
        cout<<str<<" is a palindrome\n";
    }
    else{
        cout<<str<<" isn't a palindrome\n";
    }
    
    return 0;
}
