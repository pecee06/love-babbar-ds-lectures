// Problem statement: Subtract the product and sum of digits of an integer

#include <iostream>
#include <cstdlib>
using namespace std;

int digitProduct(int n){
    int prod = 1;
    while (n != 0){
        prod *= n%10;
        n/=10;
    }
    return prod;
}

int digitSum(int n){
    int sum = 0;
    while (n != 0){
        sum += n%10;
        n/=10;
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    int n;
    cout<<"Enter a number : ";
    cin>>n;

    cout<<"Difference of product and sum of digits of "<<n<<" = ";
    cout<<abs(digitProduct(n)-digitSum(n))<<endl;
    
    return 0;
}
