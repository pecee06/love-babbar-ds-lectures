#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cout<<"Enter the value of n : ";
    cin>>n;

    int prev = 0, curr = 1, sum = 0;
    cout<<prev<<" "<<curr<<" ";
    if (n>2){
        for (int i=0; i<n-2; i++){
            sum = prev+curr;
            prev = curr;
            curr = sum;
            cout<<sum<<" ";
        }
    }
    cout<<endl;
    
    return 0;
}
