#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cout<<"Enter the value of n : ";
    cin>>n;

    for (int i=0; i<n; i++){
        // loop for printing spaces
        for (int j=0; j<n-i; j++){
            cout<<" ";
        }
        // loop for printing numbers
        for (int k=0; k<=i; k++){
            cout<<i+1;
        }
        cout<<endl;
    }
    
    return 0;
}
