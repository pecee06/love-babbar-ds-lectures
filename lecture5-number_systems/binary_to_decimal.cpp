#include <iostream>
using namespace std;

int binToDec(long n){
    int ans = 0, multiplier = 1;
    while (n!=0){
        ans += (n%10)*multiplier;
        multiplier*=2;
        n/=10;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    cout<<"Enter a number in binary number system : ";
    long n;
    cin>>n;

    cout<<n<<" in decimal = "<<binToDec(n)<<endl;
    
    return 0;
}
