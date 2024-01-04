// Problem statement: Given a 2D array, sorted row-wise & column-wise individually (not sorted as a whole). Write an effcient program to search a particular element

#include <iostream>
using namespace std;

bool isPresent(int elem, int matrix[][5], int row, int col){
    int topRow = 0, rightCol = col-1, topRightCorner;
    while (topRow<row && rightCol>=0){
        topRightCorner = matrix[topRow][rightCol];
        if (elem<topRightCorner){
            rightCol--;
        }
        else if (elem>topRightCorner){
            topRow++;
        }
        else{
            return true;
        }
    }
    return false;
}

int main(int argc, char const *argv[])
{
    int matrix[][5] = {
        {1,4,7,11,15},
        {2,5,8,12,19},
        {3,6,9,16,22},
        {10,13,14,17,24},
        {18,21,23,26,30}
    };

    int n;
    cin>>n;

    if (isPresent(n,matrix,5,5)){
        cout<<n<<" is present in the given matrix\n";
    }
    else{
        cout<<n<<" isn't present in the given matrix\n";
    }
    
    return 0;
}
