#include <iostream>
#include <queue>
using namespace std;

/*
int* firstNegatives(int* arr, int n, int k){
    int* negatives = new int[n];
    int index = 0;
    for (int i=0; i<n; i++){
        bool found = false;
        for (int j=i; j<i+k; j++){
            // Inside Window
            if (j == n) break;
            if (arr[j] < 0){
                negatives[index++] = arr[j];
                found = true;
                break;
            }
        }
        if (!found) negatives[index++] = 0;
    }
    return negatives;
}
*/

int* firstNegatives(int* arr, int n, int k){
    queue<pair<int,int>> q;

    for (int i=0; i<n; i++)
        if (arr[i] < 0) q.push(make_pair(i,arr[i]));
    
    int* negatives = new int[n];
    int index = 0;
    pair<int,int> elem;
    while (index < n){
        elem = q.front();
        if (elem.first >= index && elem.first < index+k)
            negatives[index++] = elem.second;
        else{
            negatives[index++] = 0;
            q.pop();
        }
    }
    return negatives;
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
    for (int i=0; i<n; i++)
        cin>>arr[i];
    
    cout<<"Window size : ";
    int k;
    cin>>k;

    int* N = firstNegatives(arr,n,k);
    print(N,n);
    delete[] N;

    return 0;
}