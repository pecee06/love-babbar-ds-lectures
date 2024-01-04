Array is a data structure, used to store data of identical datatype in contiguous memory locations

Benefits of array:
    * Single identifier can be used to store multiple values
    * Constant time access to elements using indices (starting from 0)

Declaration of array:
    <datatype> <identifier>[<size>];
        * Memory locations are reserved by filling garbage values into them

Instantiation of array:
    <identifier>[<index>] = value;

Simultaneous declaration & instantiation:
    <datatype> <identifier> = {
        val-1,val-2,...,val-n
    };

    * To instantiate the entire array with 0:
        <datatype> <identifier> = {};
    * To instantiate the entire array with any other value, use for-loop to traverse the array and set value at each index to some desired value

* The name of the array is a pointer (variable which stores memory address of another variable) to the first element of that array

Accessing an element of an array:
    <identifier>[<index>]

* If an array is passed as a functional argument, it is a pass by reference case, as the array identifier in itself is a pointer pointing to the address of the first element, and whatever changes you make to the parameter array in the function definition, will get reflected in the original array as well