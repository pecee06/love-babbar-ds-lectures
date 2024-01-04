#include <iostream>
using namespace std;

void rowWiseSum(int matrix[][3], int row){
    int sum;
    for (register int i=0; i<row; i++){
        sum = 0;
        for (register int j=0; j<3; j++){
            sum += matrix[i][j];
        }
        cout<<sum<<endl;
    }
}

int main(int argc, char const *argv[])
{
    int matrix[3][3] = {
        {3,4,11},{2,12,1},{7,8,7}
    };
    rowWiseSum(matrix,3);
    
    return 0;
}
