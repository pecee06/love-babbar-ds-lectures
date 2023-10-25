#include <iostream>
using namespace std;

void update(int arr[], int size){
    for (int i=0; i<size; i++){
        if (arr[i]%2){
            arr[i] = -1;
        }
        else{
            arr[i] = 1;
        }
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

    print(arr,size);
    update(arr,size);
    print(arr,size);
    
    return 0;
}
