#include <iostream>
using namespace std;

long factorial(int n){
    long ans = (long)n;
    for (int i=2; i<n; i++){
        ans *= i;
    }
    return ans;
}

int nCr(int n, int r){
    return factorial(n)/(factorial(r)*factorial(n-r));
}

int main(int argc, char const *argv[])
{
    cout<<nCr(10,2)<<endl;
    
    return 0;
}
