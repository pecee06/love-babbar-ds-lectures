// limitation: Can't handles bases greater than 10

#include <iostream>
using namespace std;

long rToDec(long n, int base){
    long ans = 0;
    int multiplier = 1;
    while (n!=0){
        ans += (n%10)*multiplier;
        multiplier*=base;
        n/=10;
    }
    return ans;
}

long decToR(long n, int base){
    long ans = 0;
    int multiplier=1;
    while (n!=0){
        ans += (n%base)*multiplier;
        multiplier*=10;
        n/=base;
    }
    return ans;
}

long rToR(long n, int base1, int base2){
    return decToR(rToDec(n,base1),base2);
}

int main(int argc, char const *argv[])
{
    cout<<"Enter base of number you want to enter : ";
    int base1;
    cin>>base1;

    cout<<"Enter the number : ";
    long n;
    cin>>n;

    cout<<"To which base you want to convert "<<n<<" : ";
    int base2;
    cin>>base2;

    cout<<n<<" in base "<<base2<<" = "<<rToR(n,base1,base2)<<endl;
    
    return 0;
}
