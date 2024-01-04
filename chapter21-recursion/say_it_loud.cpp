#include <iostream>
#include <string>
using namespace std;

void say(int n){
    if (n==0){
        return;
    }
    static string arr[] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    int index = n%10;
    say(n/10);
    cout<<arr[index]<<" ";
}

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    say(n);

    return 0;
}