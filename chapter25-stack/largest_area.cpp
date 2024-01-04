// Problem: Given an array representing heights of contiguous bars in a histogram. Find the maximum rectangular area in the figure

#include <iostream>
using namespace std;

int Max(int* arr, int n){
    int m = arr[0];
    for (int i=1; i<n; i++)
        if (arr[i] > m) m = arr[i];
    return m;
}

/*
int maxArea(int* heights, int n){   // O(n^2)
    int* areas = new int[n];
    for (int i=0; i<n; i++){
        int width = 0, check = i;
        while (check>=0){
            if (heights[check--] >= heights[i]) width++;
            else break;
        }
        check = i;
        while (check<n){
            if (heights[++check] >= heights[i]) width++;
            else break;
        }

        areas[i] = heights[i]*width;
    }
    int m = Max(areas,n);
    delete[] areas;
    return m;
}
*/

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

int maxArea(int* heights, int n){
    int* areas = new int[n];
    for (int i=0; i<n; i++){
        int width = nextSmall(i,heights,n) - prevSmall(i,heights) - 1;
        areas[i] = heights[i] * width;
    }
    int m = Max(areas,n);
    delete[] areas;
    return m;
}

int main()
{
    int n;
    cin>>n;
    int* heights = new int[n];
    for (int i=0; i<n; i++)
        cin>>heights[i];
    
    cout<<"Max possible area = "<<maxArea(heights,n)<<endl;
    delete[] heights;

    return 0;
}