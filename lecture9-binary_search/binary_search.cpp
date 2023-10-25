#include <iostream>
using namespace std;

int binarySearch(int elem, int arr[], int n) {
    int low = 0, high = n - 1, mid;

    // Check if the array is in ascending or descending order
    bool isAscending = arr[low] < arr[high];

    while (high>=low) {
        mid = low + ((high - low) / 2);

        // Check if the element is at the mid index
        if (!(elem^arr[mid])) {
            return mid;
        }

        // Update the low or high index based on the order of the array
        if ((isAscending && elem < arr[mid]) || (!isAscending && elem > arr[mid])) {
            high = mid-1;
        } else {
            low = mid+1;
        }
    }

    return -1;
}

int main(int argc, char const *argv[])
{
    int arr[] = {3,5,9,13,27};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<binarySearch(13,arr,n)<<endl;
    cout<<binarySearch(15,arr,n)<<endl;

    int arr2[] = {64,32,1,-7,-100};
    int n2 = sizeof(arr)/sizeof(arr[0]);

    cout<<binarySearch(-100,arr2,n2)<<endl;
    cout<<binarySearch(10,arr2,n2)<<endl;
    cout<<binarySearch(32,arr2,n2)<<endl;
    
    return 0;
}