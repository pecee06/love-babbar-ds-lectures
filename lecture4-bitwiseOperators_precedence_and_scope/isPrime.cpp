#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cout<<"Enter the value of n : ";
    cin>>n;

    bool isPrime = true;
    for (int i=2; i<n; i++){
        if (n%i==0){
            isPrime = false;
            break;
        }
    }

    if (isPrime){
        cout<<n<<" is prime\n";
    }
    else{
        cout<<n<<" is not prime\n";
    }
    
    return 0;
}
