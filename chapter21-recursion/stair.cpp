#include <iostream>
using namespace std;

int waysToClimbHelper(int n){
    if (n<=0){
        return 0;
    }

    return n+waysToClimbHelper(n-2);
}

int waysToClimb(int n){
    return waysToClimbHelper(n)-1;
}

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    cout<<waysToClimb(n);

    return 0;
}