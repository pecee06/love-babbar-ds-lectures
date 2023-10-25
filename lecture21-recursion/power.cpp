#include <iostream>
using namespace std;

int exp(int base, int p){
    static int ans = 1;
    if (p == 0){
        return ans;
    }
    ans = base * exp(base,p-1);
}

int main(int argc, char const *argv[])
{
    cout<<exp(2,3);

    return 0;
}