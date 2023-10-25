#include <iostream>
using namespace std;

int sumHelper(int* arr, int n, int i){
    static int ans = 0;
    if (i>=n){
        return ans;
    }
    ans += arr[i];
    sumHelper(arr,n,i+1);
}

int sum(int* arr, int n){
    sumHelper(arr,n,0);
}

int main(int argc, char const *argv[])
{
    int arr[50];
    
    int n;
    cin>>n;

    for (register int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout<<"Sum = "<<sum(arr,n)<<endl;

    return 0;
}