#include <iostream>
using namespace std;

void reverse(int arr[], int size){
    int temp;
    for (int i=0; i<size/2; i++){
        temp = arr[i];
        arr[i] = arr[(size-1)-i];
        arr[(size-1)-i] = temp;
    }
}

void print(int arr[], int size){
    for (int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(int argc, char const *argv[])
{
    int arr[] = {7,3,3,7,6,1,1,1,6,9};
    int size = sizeof(arr)/sizeof(arr[0]);

    reverse(arr,size);
    print(arr,size);
    
    return 0;
}
