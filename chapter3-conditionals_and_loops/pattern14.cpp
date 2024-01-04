#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cout<<"Enter the value of n : ";
    cin>>n;

    char c = 'A';
    for (int i=1; i<=n; i++){
        for (int j=0; j<i; j++){
            cout<<c;
        }
        cout<<endl;
        c++;
    }
    
    return 0;
}
