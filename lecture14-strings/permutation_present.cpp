// Problem statement: Given 2 strings str1 & str2, you have to check whether any of the permutation of str1 is present in str2

#include <iostream>
#include <string>
using namespace std;

bool charPresentInWindow(char c, string s, int from, int to){
    string sub = s.substr(from,to-from);
    if (sub.find(c) == string::npos){
        return false;
    }
    return true;
}

bool permutationPresent(string s1, string s2){
    int windowLeftEnd = 0, windowRightEnd = s1.length();
    int limit = s2.size(), i = 0;
    while (windowRightEnd<=limit){
        if (!charPresentInWindow(s1[i],s2,windowLeftEnd,windowRightEnd)){
            windowLeftEnd++;
            windowRightEnd++;
            i = 0;
        }
        else{
            i++;
        }
        if (s1[i]=='\0'){
            return true;
        }
    }
    return false;
}

int main(int argc, char const *argv[])
{
    string str1,str2;
    cout<<"Enter substring\n";
    getline(cin,str1);
    cout<<"Enter main string\n";
    getline(cin,str2);
    
    if (permutationPresent(str1,str2)){
        cout<<str1<<" is present in "<<str2<<endl;
    }
    else{
        cout<<str1<<" isn't present in "<<str2<<endl;
    }
    
    return 0;
}
