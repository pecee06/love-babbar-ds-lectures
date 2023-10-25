// Problem statement: Take unsigned int as input and return the number of 1s it has in its binary form

#include <iostream>
using namespace std;

int hammingWeight(unsigned int n){
    int ones = 0;
    while (n!=0){
        if (n%2!=0){
            ones++;
        }
        n/=2;
    }
    return ones;
}

int main(int argc, char const *argv[])
{
    int n;
    cout<<"Enter a number : ";
    cin>>n;

    cout<<"Hamming weight of "<<n<<" = ";
    cout<<hammingWeight(n)<<endl;
    
    return 0;
}
