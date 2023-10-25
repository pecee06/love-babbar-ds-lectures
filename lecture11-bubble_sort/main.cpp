#include <iostream>
using namespace std;

void sort(int* arr, int n, char order){
    int i, j;
    bool isSorted;
    for (int k=1; k<n; k++){
        isSorted = true;
        i=0,j=1;
        while (j<n){
            if (order=='a'){
                if (arr[i]>arr[j]){
                    swap(arr[i],arr[j]);
                    isSorted = false;
                }
            }
            else if (order=='d'){
                if (arr[i]<arr[j]){
                    swap(arr[i],arr[j]);
                    isSorted = false;
                }
            }
            i++;
            j++;
        }
        if (isSorted){
            break;
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
    int arr[] = {10,1,9,6,14,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    sort(arr,n,'d');
    print(arr,n);
    
    return 0;
}
