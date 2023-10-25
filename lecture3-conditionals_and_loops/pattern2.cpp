#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cout<<"Enter the value of n : ";
    cin>>n;

    // printing square
    for (int i=1; i<=n; i++){
        for (int j=0; j<n; j++){
            cout<<i;
        }
        cout<<endl;
    }
    
    return 0;
}
