#include <iostream>
using namespace std;

void printCount(int n){
    if (n==0){
        return;
    }
    cout<<n<<" ";
    printCount(n-1);
}

int main(int argc, char const *argv[])
{
    printCount(10);

    return 0;
}