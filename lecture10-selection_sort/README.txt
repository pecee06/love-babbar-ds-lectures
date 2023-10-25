Sorting means to arrange the elements of a container in increasing or decreasing order of some property (value in case of numeric array, alphabetical order in case of character array, length in case of strings)

There are many sorting algorithms, selection sort is one of them
In selection sort, we find the minimum (or maximum) element in each pass of a subarray of the given array and place it in its right position

Approach (for numeric arrays)-
Maintain an index i (initially 0)
Assume a subarray from i to n-1 {n -> size of array}
Find the minimum element of the subarray
Swap it with the element at index = i
After n-1 passes, the array will be sorted

Analysis-
Time complexity - O(n^2)
Space complexity - O(1)
Adaptive - No
Stable - Yes