#include <iostream>
using namespace std;

bool isEven(int n){
    return !(n%2);
}

int main(int argc, char const *argv[])
{
    int n;
    cout<<"Enter a number : ";
    cin>>n;

    if (n<=0){
        cout<<"Invalid input\n";
    }
    else{
        if (isEven(n)){
            cout<<n<<" is even\n";
        }
        else{
            cout<<n<<" is odd\n";
        }
    }

    
    return 0;
}
