#include <iostream>
using namespace std;

bool linearSearch(int val, int arr[], int size){
    for (int i=0; i<size; i++){
        if (arr[i] == val){
            return true;
        }
    }
    return false;
}

int main(int argc, char const *argv[])
{
    int arr[] = {5,7,-2,10,22,-2,0,5,22,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    int val = 4;

    if (linearSearch(val,arr,size)){
        cout<<val<<" is present in the array\n";
    }
    else{
        cout<<val<<" isn't present in the array\n";
    }
    
    return 0;
}
