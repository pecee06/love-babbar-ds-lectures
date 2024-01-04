#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> s;
    int n, temp;
    cin>>n;
    for (int i=0; i<n; i++){
        cin>>temp;
        s.push(temp);
    }

    int* arr = new int[n/2];
    int i;
    for (i=0; i<n/2; i++){
        arr[i] = s.top();
        s.pop();
    }
    cout<<s.top()<<endl;
    s.pop();
    while (i>=0){
        s.push(arr[i]);
        i--;
    }

    delete[] arr;

    return 0;
}