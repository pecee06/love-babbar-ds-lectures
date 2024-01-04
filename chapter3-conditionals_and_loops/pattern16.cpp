#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cout<<"Enter the value of n : ";
    cin>>n;

    char c1 = 'A', c2;
    for (int i=1; i<=n; i++){
        c2 = c1++;
        for (int j=0; j<i; j++){
            cout<<c2++;
        }
        cout<<endl;
    }
    
    return 0;
}
