#include <iostream>
using namespace std;

int nthTerm(int a, int d, int n){
    return a+((n-1)*d);
}

int main(int argc, char const *argv[])
{
    // Tn = a+((n-1)*d) -> general term of AP
    cout<<nthTerm(35,21,4);
    return 0;
}
