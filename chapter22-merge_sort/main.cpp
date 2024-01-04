#include <iostream>
using namespace std;

void merge(int* arr, int s, int m, int e){
    int* temp = new int[e-s+1];
    register int i = s, j = m+1, index = 0;
    while (i<=m && j<=e){
        if (arr[i]<=arr[j]){
            temp[index++] = arr[i++];
        }
        else{
            temp[index++] = arr[j++];
        }
    }

    while (i<=m){
        temp[index++] = arr[i++];
    }
    while (j<=e){
        temp[index++] = arr[j++];
    }

    for (register int k=s; k<=e; k++){
        arr[k] = temp[k-s];
    }

    delete[] temp;
}

void sortHelper(int* arr, int s, int e){
    if (s>=e){
        return;
    }
    int m = (s+e)/2;
    sortHelper(arr,s,m);
    sortHelper(arr,m+1,e);
    merge(arr,s,m,e);
}

void sort(int* arr, int size){
    sortHelper(arr,0,size-1);
}

void print(int* arr, int n){
    for (register int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(int argc, char const *argv[])
{
    int arr[] = {9,3,7,5,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    sort(arr,n);
    print(arr,n);

    return 0;
}