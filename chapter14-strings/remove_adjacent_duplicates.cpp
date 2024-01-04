#include <iostream>
#include <string>
using namespace std;

void removeAdjacentDuplicates(string& str){
    static int pos = 0;
    bool dupsPresent = false;
    for (int i=0; i<str.length()-1; i++){
        if (str[i]==str[i+1]){
            dupsPresent = true;
            pos = i;
            str.erase(pos,2);
        }
    }
    if (dupsPresent)
        removeAdjacentDuplicates(str);
}

int main(int argc, char const *argv[])
{
    string str;
    cout<<"Enter a string\n";
    getline(cin,str);

    removeAdjacentDuplicates(str);
    cout<<str<<endl;
    
    return 0;
}
