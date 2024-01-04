#include <iostream>
using namespace std;

int exp(int m, int n){
    if (n==1){
        return m;
    }
    return m*exp(m,n-1);
}

int main(int argc, char const *argv[])
{
    cout<<exp(2,3)<<endl;

    return 0;
}