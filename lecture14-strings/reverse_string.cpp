#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    char word[20];
    cout<<"Enter a word : ";
    cin>>word;

    int i=0, n = 0;
    while (word[i++]!='\0'){
        n++;
    }

    for (int i=0; i<(n/2); i++){
        swap(word[i],word[n-1-i]);
    }

    cout<<"Reversed word\n"<<word<<endl;
    
    return 0;
}
