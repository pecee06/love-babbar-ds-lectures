#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cout<<"Enter a number : ";
    cin>>n;

    bool isPrime = true;

    if (n<2){
        isPrime = false;
    }
    else{
        for (int i=2; i<n; i++){
            isPrime = (n%i==0)?false:true;
            break;
        }
    }

    if (isPrime){
        cout<<n<<" is a prime number\n";
    }
    else{
        cout<<n<<" is not a prime number\n";
    }
    
    return 0;
}
