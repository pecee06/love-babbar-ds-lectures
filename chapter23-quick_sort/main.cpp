#include <iostream>
using namespace std;

int partition(int* arr, int s, int e){
    int smallerElems = 0, partAbout = arr[s];
    for (register int i=s; i<=e; i++){
        if (arr[i]<partAbout){
            smallerElems++;
        }
    }
    swap(arr[s],arr[s+smallerElems]);

    register int i=s, j=e;
    while (i<j){
        if (arr[i]>=partAbout && arr[j]<partAbout){
            swap(arr[i++],arr[j--]);
        }
        else if (arr[i]>=partAbout){
            j--;
        }
        else if (arr[j]<=partAbout){
            i++;
        }
    }

    return s+smallerElems;
}

void sortHelper(int* arr, int s, int e){
    if (s>=e){
        return;
    }
    int partIndex = partition(arr,s,e);
    sortHelper(arr,s,partIndex-1);
    sortHelper(arr,partIndex+1,e);
}

void sort(int* arr, int n){
    sortHelper(arr,0,n-1);
}

void print(int* arr, int n){
    for (register int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(int argc, char const *argv[])
{
    int arr[] = {9,3,7,5,3,10,5,5,1,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    sort(arr,n);
    print(arr,n);

    return 0;
}