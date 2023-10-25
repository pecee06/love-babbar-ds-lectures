#include <iostream>
#include <limits.h>
using namespace std;

int minIn(int* arr, int n, int from){
    int min = INT_MAX, minIndex = 0;
    for (int i=from; i<n; i++){
        if (arr[i]<min){
            min = arr[i];
            minIndex = i;
        }
    }
    return minIndex;
}

int maxIn(int* arr, int n, int from){
    int max = INT_MIN, maxIndex = 0;
    for (int i=from; i<n; i++){
        if (arr[i]>max){
            max = arr[i];
            maxIndex = i;
        }
    }
    return maxIndex;
}

void sort(int* arr, int n, char order){
    for (int i=0; i<n-1; i++){
        if (order=='a'){
            swap(arr[i],arr[minIn(arr,n,i)]);
        }
        else if (order=='d'){
            swap(arr[i],arr[maxIn(arr,n,i)]);
        }
    }
}

void print(int* arr, int n){
    for (int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(int argc, char const *argv[])
{
    int arr[] = {64,11,12,22,11};
    int n = sizeof(arr)/sizeof(arr[0]);
    sort(arr,n,'a');
    print(arr,n);
    sort(arr,n,'d');
    print(arr,n);
    
    return 0;
}
