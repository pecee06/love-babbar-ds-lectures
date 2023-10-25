#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int m,n;
    cout<<"Enter number of rows : ";
    cin>>m;
    cout<<"Enter number of columns : ";
    cin>>n;

    int** arr = new int* [n];
    for (register int i=0; i<n; i++){
        arr[i] = new int[m];
    }

    for (register int i=0; i<m; i++){
        cout<<"Enter row "<<i+1<<" elements\n";
        for (register int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    cout<<"Entered 2D array\n";
    for (register int i=0; i<m; i++){
        for (register int j=0; j<n; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    // Freeing the memory allocated dynamically
    for (register int i=0; i<n; i++){
        delete[] arr[i];
    }

    delete[] arr;
    
    return 0;
}
