#include <iostream>
using namespace std;

int gcd (int m, int n){
    // Euclid's algo - gcd(m,n) = gcd(m-n,n) {assuming m>n}
    if (!m){
        return n;
    }
    if (!n){
        return m;
    }
    
    if (m>n){
        return gcd(m-n,n);
    }
    else{
        return gcd(n-m,m);
    }
}

int main(int argc, char const *argv[])
{
    int m,n;
    cin>>m>>n;

    cout<<"GCD of "<<m<<" and "<<n<<" = "<<gcd(m,n)<<endl;
    
    return 0;
}
