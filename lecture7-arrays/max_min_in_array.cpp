#include <iostream>
using namespace std;

int max(int arr[], int size){
    int val = arr[0];
    for (int i=1; i<size; i++){
        if (arr[i]>val){
            val = arr[i];
        }
    }
    return val;
}

int min(int arr[], int size){
    int val = arr[0];
    for (int i=1; i<size; i++){
        if (arr[i]<val){
            val = arr[i];
        }
    }
    return val;
}

int main(int argc, char const *argv[])
{
    int arr[] = {5,6,8,9,0,2,1,4,34,55,2,7};
    int size = sizeof(arr)/sizeof(arr[0]);

    cout<<"Max = "<<max(arr,size)<<endl;
    cout<<"Min = "<<min(arr,size)<<endl;
    
    return 0;
}
