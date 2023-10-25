#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cout<<"Enter the value of n : ";
    cin>>n;

    int sum = 0;
    for (int i=2; i<=n; i+=2){
        sum+=i;
    }
    cout<<"Sum = "<<sum<<endl;
    
    return 0;
}
