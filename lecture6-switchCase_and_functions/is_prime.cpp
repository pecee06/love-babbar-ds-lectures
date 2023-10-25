#include <iostream>
using namespace std;

bool isPrime(int n){
    if (n<2 || (n!=2 && !(n%2))){
        return false;
    }
    
    for (int i=3; i<n; i++){
        if (!(n%i)){
            return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    cout<<isPrime(23)<<endl;
    cout<<isPrime(0)<<endl;
    cout<<isPrime(2)<<endl;
    cout<<isPrime(10)<<endl;
    cout<<isPrime(15)<<endl;
    
    return 0;
}
