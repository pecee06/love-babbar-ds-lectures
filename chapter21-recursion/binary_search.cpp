#include <iostream>
using namespace std;

bool foundHelper(int* arr, int from, int to, int elem){
    int mid = (from+to)/2;
    if (from>to){
        return false;
    }

    if (arr[mid]>elem){
        foundHelper(arr,from,mid-1,elem);
    }
    else if (arr[mid]<elem){
        foundHelper(arr,mid+1,to,elem);
    }
    else{
        return true;
    }
}

bool found(int* arr, int n, int elem){
    return foundHelper(arr,0,n-1,elem);
}

int main(int argc, char const *argv[])
{
    int arr[] = {0,7,8,13,15,17,17};
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