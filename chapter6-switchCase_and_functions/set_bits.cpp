// Problem statement: return the number of set-bits (1s) in a&b (both entered by user)

#include <iostream>
using namespace std;

int setBits(int a, int b){
    int n = a&b;
    int noOfSetBits = 0;
    while (n!=0){
        if (n&1){
            noOfSetBits++;
        }
        n = n>>1;
    }
    return noOfSetBits;
}

int main(int argc, char const *argv[])
{
    cout<<setBits(2,3)<<endl;
    
    return 0;
}
