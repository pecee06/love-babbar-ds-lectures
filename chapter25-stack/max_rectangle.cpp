// Problem: Given a binary matrix, find the area of largest possible rectangle having all 1s

#include <iostream>
using namespace std;

int prevSmall(int curr, int* arr){
    int elem = arr[curr--];
    while (curr>=0)
        if (arr[curr--] < elem) return curr+1;
    return -1;
}
int nextSmall(int curr, int* arr, int n){
    int elem = arr[curr++];
    while (curr<n)
        if (arr[curr++] < elem) return curr-1;
    return n;
}

int Max(int* arr, int n){
    int m = arr[0];
    for (int i=1; i<n; i++)
        if (arr[i] > m) m = arr[i];
    return m;
}

int maxAreaHelper(int* heights, int n){
    int* areas = new int[n];
    for (int i=0; i<n; i++){
        int width = nextSmall(i,heights,n) - prevSmall(i,heights) - 1;
        areas[i] = heights[i] * width;
    }
    int m = Max(areas,n);
    delete[] areas;
    return m;
}

int maxArea(int** matrix, int n){
    int* heights = new int[n];
    for (int i=0; i<n; i++)
        heights[i] = 0;

    int max = 0;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (matrix[i][j]) heights[j]++;
            else heights[j] = 0;
        }

        int m = maxAreaHelper(heights,n);
        (m > max)?max = m:true;
    }

    return max;
}

int main()
{
    int n;
    cin>>n;
    int** matrix = new int*[n];
    for (int i=0; i<n; i++){
        matrix[i] = new int[n];
        for (int j=0; j<n; j++){
            cin>>matrix[i][j];
        }
    }

    cout<<"Maximum area = "<<maxArea(matrix,n)<<endl;

    return 0;
}