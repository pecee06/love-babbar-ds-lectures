#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    char c;
    cout<<"Enter a character : ";
    cin>>c;

    if (c>=48 && c<=57){
        cout<<"Entered character is numeric\n";
    }
    else if (c>=65 && c<=90){
        cout<<"Entered character is an uppercase letter\n";
    }
    else if (c>=97 && c<=122){
        cout<<"Entered character is a lowecase letter\n";
    }
    else{
        cout<<"Special character\n";
    }
    
    return 0;
}
