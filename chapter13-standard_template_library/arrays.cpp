#include <iostream>
#include <array>
using namespace std;

int main(int argc, char const *argv[])
{
    array<int,5> arr = {7,2,9,10,11};
    cout<<arr[1]<<endl;

    for (auto it=arr.begin(); it!=arr.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    array<int,0> arr2;
    cout<<arr.empty()<<endl;
    cout<<arr2.empty()<<endl;

    cout<<arr.back()<<endl;

    array<int,5> arr3;
    arr3.fill(3);
    for (auto it=arr3.begin(); it!=arr3.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    arr.swap(arr3);
    for (auto it=arr3.begin(); it!=arr3.end(); it++){
        cout<<*it<<" ";
    }
    
    return 0;
}
