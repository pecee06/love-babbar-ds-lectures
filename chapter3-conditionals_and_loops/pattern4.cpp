#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cout<<"Enter the value of n : ";
    cin>>n;

    for (int i=0; i<n; i++){
        for (int j=n; j>=1; j--){
            cout<<j;
        }
        cout<<endl;
    }
    
    return 0;
}