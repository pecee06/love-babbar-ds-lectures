#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    float c,f;
    cout<<"Enter temperature in fahrenheit : ";
    cin>>f;

    c = 5*(f-32)/9;

    cout<<"Temperature in Celcius = "<<c<<endl;

    return 0;
}
