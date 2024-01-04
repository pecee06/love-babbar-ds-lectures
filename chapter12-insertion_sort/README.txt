In insertion sort we assume 2 subarrays, one sorted and other unsorted. We take elements from the unsorted subarray one by one and insert them in the sorted subarray in such a way that it remain sorted

Approach-
Maintain 2 indices sortedTill & unsortedFrom
sortedTill = 0, unsortedFrom = 1 (initially)
Store first element of the unsorted subarray in temp and compare it with each element of sorted subarray starting from index sortedTill to 0
Keep shifting elements of sorted subarray to their respective next position till temp < element
Once the condition is not satisfied place temp in that index

Analysis-
Time complexity - O(n^2)
Space complexity - O(1)
Adaptive - Yes {best case time complexity - O(n)}
Stable - Yes