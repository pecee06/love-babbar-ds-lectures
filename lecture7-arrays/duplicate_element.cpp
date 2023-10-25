#include <iostream>
using namespace std;

int duplicateElementIndex(int arr[], int size){
    for (int i=0; i<size; i++){
        for (int j=i+1; j<size; j++){
            if (arr[i] == arr[j]){
                return j;
            }
        }
    }
    return -1;  // In case no duplicate element is found
}

int main(int argc, char const *argv[])
{
    int arr[] = {1,4,15,6,8,4,9,0,7};
    int size = sizeof(arr)/sizeof(arr[0]);

    cout<<"Index of duplicate element in array = "<<duplicateElementIndex(arr,size)<<endl;
    
    return 0;
}
