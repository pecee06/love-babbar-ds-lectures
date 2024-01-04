#include <iostream>
using namespace std;

void sort(int* arr, int size){
    if (size == 1){
        return;
    }
    for (register int i=0; i<size-1; i++){
        if (arr[i+1] < arr[i]){
            swap(arr[i],arr[i+1]);
        }
    }
    sort(arr,size-1);
}

void print(int* arr, int size){
    for (register int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(int argc, char const *argv[])
{
    int arr[] = {4,6,1,2,10,-2,0,15};
    int n = sizeof(arr)/sizeof(arr[0]);
    sort(arr,n);
    print(arr,n);

    return 0;
}