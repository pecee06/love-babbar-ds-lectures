#include <iostream>
using namespace std;

int maxValIndex(int* arr, int n){
    int max = arr[0], maxIndex = 0;
    for (register int i=1; i<n; i++){
        if (arr[i]>max){
            max = arr[i];
            maxIndex = i;
        }
    }
    return maxIndex;
}

int greatestRow(int matrix[][3], int row, int col){
    // number of columns mentioned while decalring a matrix, is the maximum number of column it can have, you can certainely make a matrix with columns less than what's mentioned while declaration. Ofcourse there will be memory wastage
    int* sums = new int[row];
    int sum;
    for (register int i=0; i<row; i++){
        sum = 0;
        for (register int j=0; j<col; j++){
            sum += matrix[i][j];
        }
        sums[i] = sum;
    }
    int ans =  maxValIndex(sums,row);
    delete[] sums;
    return ans;
}

int main(int argc, char const *argv[])
{
    int matrix[2][3] = {
        {2,4},{1,7}
    };

    cout<<greatestRow(matrix,2,2);
    
    return 0;
}
