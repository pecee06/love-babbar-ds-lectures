#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cout<<"Enter the value of n : ";
    cin>>n;

    for (int i=1; i<=n; i++){
        int var = i;
        for (int j=0; j<i; j++){
            cout<<var--;
        }
        cout<<endl;
    }
    
    return 0;
}