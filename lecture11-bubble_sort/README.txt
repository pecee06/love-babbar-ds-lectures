In bubble sort, we check the relative order of each pair of consecutive elements, if wrong, they're swapped. Doing this iteratively, we get the max (or min) element at the last index after each pass. After n-1 such passes, we'll get or sorted array

Approach-
Maintain 2 indices, i & j
i=0, j=1 (initially)
Compare each consecutive pair and swap if required
After each pass, increment i & j by 1 untill i=n-1
After n-1 passes, the array will be sorted

Analysis-
Time complexity - O(n^2)
Space complexity - O(1)
Adaptive - Yes {best case time complexity - O(n)}
Stable - Yes