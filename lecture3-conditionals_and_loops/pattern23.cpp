#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cout<<"Enter the value of n : ";
    cin>>n;

    int var;
    for (int i=0; i<n; i++){
        var = i+1;
        // loop for printing spaces
        for (int j=0; j<i; j++){
            cout<<" ";
        }
        // loop for printing numbers
        for (int k=0; k<n-i; k++){
            cout<<var++;
        }
        cout<<endl;
    }
    
    return 0;
}
