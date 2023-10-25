#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int row,col;
    cout<<"Enter number of rows : ";
    cin>>row;

    cout<<"Enter numeber of columns : ";
    cin>>col;

    for (int i=0; i<row; i++){
        for (int j=0; j<col; j++){
            cout<<"*";
        }
        cout<<endl;
    }
    
    return 0;
}
