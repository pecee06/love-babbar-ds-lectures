// Problem statement: Given a matrix, you have to print it column wise but in a sinusoidal manner, i.e., first column top top bottom, next one bottom to top and so on

#include <iostream>
using namespace std;

void makeWave(int matrix[][4], int row){
    for (register int i=0; i<4; i++){
        for (register int j=0; j<row; j++){
            if (i%2){
                cout<<matrix[row-j-1][i]<<" ";
            }
            else{
                cout<<matrix[j][i]<<" ";
            }
        }
        cout<<"\t";
    }
}

int main(int argc, char const *argv[])
{
    int matrix[5][4] = {
        {1,2,3,4},
        {4,5,6,7},
        {7,8,9,10},
        {10,11,12,13},
        {13,14,15,16}
    };

    makeWave(matrix,5);
    
    return 0;
}
