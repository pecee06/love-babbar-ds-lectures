#include <iostream>
using namespace std;

void printCounting(int till){
    for (int i=1; i<=till; i++){
        cout<<i<<endl;
    }
}

int main(int argc, char const *argv[])
{
    printCounting(15);
    
    return 0;
}
