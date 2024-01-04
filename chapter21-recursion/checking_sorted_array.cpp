#include <iostream>
using namespace std;

bool isSortedHelper(int* arr, int n, int i){
    if (i>=n){
        return true;
    }
    if (arr[i+1]>arr[i]){
        isSortedHelper(arr,n,i+1);
    }
    else{
        return false;
    }
}

bool isSorted(int* arr, int n){
    return isSortedHelper(arr,n,0);
}

int main(int argc, char const *argv[])
{
    int arr[50];
    
    int n;
    cin>>n;

    for (register int i=0; i<n; i++){
        cin>>arr[i];
    }

    if (isSorted(arr,n)){
        cout<<"The array is sorted\n";
    }
    else{
        cout<<"The array isn't sorted\n";
    }

    return 0;
}