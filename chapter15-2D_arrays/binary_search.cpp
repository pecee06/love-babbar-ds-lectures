#include <iostream>
using namespace std;

int inSubarray(int elem, int matrix[][5], int row, int col){
    for (register int i=0; i<row; i++){
        if (elem>=matrix[i][0] && elem<=matrix[i][col-1]){
            return i;
        }
    }
    return -1;
}

bool isPresent(int elem, int matrix[][5], int row, int col){
    int inRow = inSubarray(elem,matrix,row,col);
    if (inRow==-1){
        return false;
    }
    register int i=0, j=col-1, mid;
    while (j>=i){
        mid = (i+j)/2;
        if (elem<matrix[inRow][mid]){
            j=mid-1;
        }
        else if (elem>matrix[inRow][mid]){
            i=mid+1;
        }
        else{
            return true;
        }
    }
    return false;
}

// alternate approach
bool isPresentEfficient(int elem, int matrix[][5], int row, int col){
    register int i=0, j=row*col-1, mid, val;
    while (j>=i){
        mid = (i+j)/2;
        val = matrix[mid/col][mid%col];
        if (elem<val){
            j=mid-1;
        }
        else if (elem>val){
            i=mid+1;
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
        {1,3,5,7},
        {10,11,16,20},
        {22,30,34,60}
    };

    int n;
    cin>>n;

    if (isPresentEfficient(n,matrix,3,4)){
        cout<<n<<" is present in given matrix\n";
    }
    else{
        cout<<n<<" isn't present in given matrix\n";
    }
    
    return 0;
}
