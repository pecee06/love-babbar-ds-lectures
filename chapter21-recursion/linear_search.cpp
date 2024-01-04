#include <iostream>
using namespace std;

bool found(int* arr, int n, int elem){
    if (n==0){
        return false;
    }
    if (*arr == elem){
        return true;
    }
    found(arr+1,n-1,elem);
}

int main(int argc, char const *argv[])
{
    int arr[] = {4,6,8,4,0,2,4,5,11,31,15,1,1,7};;
    int n = sizeof(arr)/sizeof(arr[0]);
    
    int elem;
    cin>>elem;

    if (found(arr,n,elem)){
        cout<<elem<<" is present\n";
    }
    else{
        cout<<elem<<" ain't present\n";
    }

    return 0;
}