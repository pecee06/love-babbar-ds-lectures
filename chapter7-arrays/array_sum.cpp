#include <iostream>
using namespace std;

int sum(int arr[], int size){
    int val = 0;
    for (int i=0; i<size; i++){
        val += arr[i];
    }
    return val;
}

int main(int argc, char const *argv[])
{
    int arr[] = {1,4,7,8,610,43,-8,-740};
    int size = sizeof(arr)/sizeof(arr[0]);

    cout<<"Sum of elements of array = "<<sum(arr,size);
    
    return 0;
}
