In searching algos, we make a function which returns the index of the required element in the array, if it's present, else returns -1

Now we have a method called as linear search to perform this operation in linear time, but in case our array is already sorted, we can use binary search which performs the search in O(log n)

Binary search is an algorithm that finds the position of a target value within a sorted array. It compares the target value to the middle element of the array; if they are unequal, the half in which the target cannot lie is eliminated and the search continues on the remaining half until it is successful. If the search ends with the remaining half being empty, the target is not in the array.