#include <iostream>
#include <stack>
using namespace std;

int* nextSmallElems(int* arr, int n){
    stack<int> s;
    s.push(-1);
    int* sol = new int[n];
    int index = n-1;
    for (int i=n-1; i>=0; i--){
        if (s.top() < arr[i]){
            sol[index--] = s.top();
            s.push(arr[i]);
        }
        else{
            while (s.top() >= arr[i]) s.pop();
            sol[index--] = s.top();
            s.push(arr[i]);
        }
    }
    return sol;
}

void print(int* arr, int n){
    for (int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main()
{
    int arr[] = {2,1,4,3};
    int n = sizeof(arr)/sizeof(int);
    int* sol = nextSmallElems(arr,n);

    print(sol,n);
    delete[] sol;

    return 0;
}