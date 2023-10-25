// Problem statement: Given a matrix, you have to rotate it by 90 deg inplace

#include <iostream>
#include <vector>
using namespace std;

void rotate(int matrix[][5], int row, int col){
    vector<int> temp;
    for (register int i=0; i<row; i++){
        for (register int j=0; j<col; j++){
            temp.push_back(matrix[i][j]);
        }
    }
    for (register int i=0; i<row; i++){
        for (register int j=0; j<col; j++){
            matrix[i][j] = temp[(row*(row-j-1))+i];
        }
    }
}

void print(int matrix[][5], int row, int col){
    for (register int i=0; i<row; i++){
        for (register int j=0; j<col; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(int argc, char const *argv[])
{
    int matrix[][5] = {
        {1,2,3,4},
        {4,5,6,7},
        {5,6,7,8},
        {6,7,8,9}
    };

    cout<<"rotated matrix\n";
    rotate(matrix,4,4);
    print(matrix,4,4);
    
    return 0;
}
