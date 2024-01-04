In merge sort, we first break the given array into subarrays of length 1 (as singleton arrays are always sorted) and then merge them in a sorted fashion

Approach-
Call the sorting function for array
Which in turn will call the function for left half and then right half of the array
After we got 2 sorted arrays, merge them
The merge function makes a temporary array on which the elements from passed subarray is entered in a sorted fashion
Finally the temporary array is copied into the subarray

Analysis-
Time complexity - O(n*logn)
Space complexity - O(n)
Adaptive - No
Stable - Yes
Recursive - Yes