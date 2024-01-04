// Problem statement: Given a string of words, replace all the spaces with "@40" in the original string

#include <iostream>
#include <string>
using namespace std;

void replaceSpaces(string& str){
    int i=0;
    while (str[i]!='\0'){
        if (str[i] == ' '){
            str.replace(i,1,"@40");
        }
        i++;
    }
}

int main(int argc, char const *argv[])
{
    string str;
    cout<<"Enter a string\n";
    getline(cin,str);
    replaceSpaces(str);
    cout<<"New string : "<<str<<endl;
    
    return 0;
}
