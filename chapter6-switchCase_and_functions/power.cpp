#include <iostream>
using namespace std;

int power(int base, int p){
    int ans = base;
    for (int i=1; i<p; i++){
        ans *= base;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    cout<<power(3,3)<<endl;
    
    return 0;
}
