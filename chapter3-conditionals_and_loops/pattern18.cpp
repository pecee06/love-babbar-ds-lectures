#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cout<<"Enter the value of n : ";
    cin>>n;

    for (int i=1; i<=n; i++){
        // loop for printing spaces
        for (int j=n-i; j>0; j--){
            cout<<" ";
        }
        // loop for printing stars
        for (int k=0; k<i; k++){
            cout<<"*";
        }
        cout<<endl;
    }
    
    return 0;
}
