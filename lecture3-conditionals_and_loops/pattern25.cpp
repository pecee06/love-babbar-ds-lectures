#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cout<<"Enter the value of n : ";
    cin>>n;

    int var = 1;
    for (int i=0; i<n; i++){
        for (int j=1; j<n-i; j++){
            cout<<" ";
        }
        for (int k=0; k<=i; k++){
            cout<<var++;
        }
        var--;
        for (int l=0; l<i; l++){
            cout<<--var;
        }
        cout<<endl;
    }
    
    return 0;
}
