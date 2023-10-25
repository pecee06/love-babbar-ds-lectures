#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cout<<"Enter the value of n : ";
    cin>>n;

    int var;
    for (int i=0; i<n; i++){
        var = 1;
        for (int j=0; j<n-i; j++){
            cout<<var++;
        }
        for (int k=0; k<i; k++){
            cout<<"**";
        }
        for (int l=0; l<n-i; l++){
            cout<<--var;
        }
        cout<<endl;
    }
    
    return 0;
}
