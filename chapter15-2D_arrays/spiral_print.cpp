#include <iostream>
using namespace std;

void printSpiral(int matrix[][5], int row, int col){
    register int topRow = 0, bottomRow = row-1, leftCol = 0, rightCol = col-1, i;
    while (topRow<=bottomRow && leftCol<=rightCol){
        // printing top row
        for (i=leftCol; i<=rightCol; i++){
            cout<<matrix[topRow][i]<<" ";
        }
        topRow++;
        // printing right col
        for (i=topRow; i<=bottomRow; i++){
            cout<<matrix[i][rightCol]<<" ";
        }
        rightCol--;
        // printing bottom row
        for (i=rightCol; i>=leftCol && topRow<=bottomRow; i--){
            cout<<matrix[bottomRow][i]<<" ";
        }
        bottomRow--;
        // printing left col
        for (i=bottomRow; i>=topRow && leftCol<=rightCol; i--){
            cout<<matrix[i][leftCol]<<" ";
        }
        leftCol++;
    }
}

int main(int argc, char const *argv[])
{
    int matrix[][5] = {
        {1,2,3,4},
        {4,5,6,5},
        {7,8,9,6}
    };

    printSpiral(matrix,3,4);
    
    return 0;
}
