#include <iostream>
using namespace std;

void sort(int* arr, int n, char order){
    int sortedTill = 0, unsortedFrom = 1, temp, i;
    bool atCorrectPosition;
    while (sortedTill < n-1){
        temp = arr[unsortedFrom];
        i = sortedTill;
        if (order=='a'){
            while (i>=0 && temp<arr[i]){
                arr[i+1] = arr[i--];
            }
        }
        else if (order=='d'){
            while (i>=0 && temp>arr[i]){
                arr[i+1] = arr[i--];
            }
        }
        arr[i+1] = temp;
        sortedTill++;
        unsortedFrom++;
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
    int arr[] = {4,12,11,20,12,-8};
    int n = sizeof(arr)/sizeof(arr[0]);
    sort(arr,n,'d');
    print(arr,n);
    
    return 0;
}
