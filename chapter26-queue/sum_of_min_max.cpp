// Problem:  Given an array of size n, you have to return an array having sums of max and min elements of each subarray of size k

#include <iostream>
using namespace std;

int* f(int* arr, int n, int k){
    pair<int,int> min, max;
    min.first = max.first = 0;
    min.second = max.second = arr[0];
    for (int i=1; i<k; i++){
        if (arr[i] > max.second){
            max.first = i;
            max.second = arr[i];
        }
        else if (arr[i] < min.second){
            min.first = i;
            min.second = arr[i];
        }
    }

    int* sums = new int[n-k+1];
    sums[0] = min.second + max.second;
    int index = 1;

    for (int i=k; i<n; i++){
        if (arr[i] <= min.second){
            min.first = i;
            min.second = arr[i];
        }
        else if (arr[i] >= max.second){
            max.first = i;
            max.second = arr[i];
        }
        else if (i-min.first == k){
            min.first = i;
            min.second = arr[i];
        }
        else if (i-max.first == k){
            max.first = i;
            max.second = arr[i];
        }
        sums[index++] = min.second + max.second;
    }

    return sums;
}

void print(int* arr, int n){
    for (int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main()
{
    int n;
    cin>>n;
    int* arr = new int[n];
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout<<"Window size : ";
    int k;
    cin>>k;

    int* sol = f(arr,n,k);
    print(sol,n-k+1);

    return 0;
}