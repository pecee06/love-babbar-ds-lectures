#include <iostream>
using namespace std;

long decToBin(int n){
    int multiplier=1;
    long ans = 0;
    while (n!=0){
        ans += (n%2)*multiplier;
        multiplier*=10;
        n/=2;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    cout<<"Enter a number in decimal number system : ";
    int n;
    cin>>n;

    cout<<n<<" in binary = "<<decToBin(n)<<endl;
    
    return 0;
}
