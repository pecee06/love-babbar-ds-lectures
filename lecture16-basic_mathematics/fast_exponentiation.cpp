#include <iostream>
using namespace std;

int power(int m, int n){
    // calculates m^n
    // concept - if n is even, m^n = (m^(n/2))^2, else m^n = ((m^(n/2))^2)*m

    if (n == 1){
        return m;
    }
    
    int temp = power(m, n/2);
    if (n % 2 == 0){
        // n is even
        return temp * temp;
    }
    else{
        // n is odd
        return m * temp * temp;
    }
}

int main(int argc, char const *argv[])
{
    int m,n;
    cin>>m>>n;
    cout<<power(m,n)<<endl;
    
    return 0;
}
