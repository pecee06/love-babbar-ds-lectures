#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int rows;
    cout<<"Enter number of rows : ";
    cin>>rows;

    int** arr = new int*[rows];
    int* sizes = new int[rows];

    for (register int i=0; i<rows; i++){
        cout<<"Number of elements in row "<<i+1<<" : ";
        cin>>sizes[i];
        arr[i] = new int[sizes[i]];
    }

    for (register int i=0; i<rows; i++){
        cout<<"Enter row "<<i+1<<" elements\n";
        for (register int j=0; j<sizes[i]; j++){
            cin>>arr[i][j];
        }
    }

    cout<<"Entered jagged array\n";
    for (register int i=0; i<rows; i++){
        for (register int j=0; j<sizes[i]; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    for (register int i=0; i<rows; i++){
        delete[] arr[i];
    }

    delete[] arr;
    
    return 0;
}
