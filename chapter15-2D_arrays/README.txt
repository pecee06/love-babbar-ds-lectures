A 2D array in C++ is an array of arrays. It can be visualized as a matrix with rows and columns.

Syntax to declare-
int arr[m][n] -> a matrix with m rows and n columns

Eg. int arr[2][3] -> this can be visualized as an array of capacity 2 each element of which is an array itself of capacity 3

Decalration & Instantiation-
int arr[3][2] = {
    {1,2},{3,4},{5,6}
}

Accessing an element-
arr[i][j] -> element at ith row and jth column (row and column indexing starts from 0)