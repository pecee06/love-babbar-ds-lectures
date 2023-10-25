#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    char word[20];
    cout<<"Enter a word : ";
    cin>>word;

    int i=0, len = 0;
    while (word[i++]!='\0'){
        len++;
    }
    cout<<word<<" has "<<len<<" characters\n";
    // Note that, the capacity of string was 20, but its size need not be 20
    
    return 0;
}
