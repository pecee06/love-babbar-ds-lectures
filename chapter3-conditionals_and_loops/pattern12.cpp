#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cout<<"Enter the value of n : ";
    cin>>n;

    char c = 'A';
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout<<c++;
        }
        cout<<endl;
    }
    
    return 0;
}
