#include <iostream>
using namespace std;

bool isPresent(int elem, int matrix[][3], int row){
    for (register int i=0; i<row; i++){
        for (register int j=0; j<3; j++){
            if (matrix[i][j] == elem){
                return true;
            }
        }
    }
    return false;
    // Though it may seem that the time complexity of this function is O(n^2) due to nested loops. But the loop runs 3*row times, that's the size of the matrix, i.e., n. Thus its complexity is O(n)
}

int main(int argc, char const *argv[])
{
    int matrix[2][3] = {
        {87,26,0},{1,97,45}
    };

    int n;
    cin>>n;

    if (isPresent(n,matrix,2)){
        cout<<n<<" is present in the given matrix\n";
    }
    else{
        cout<<n<<" isn't present in the given matrix\n";
    }
    
    return 0;
}
