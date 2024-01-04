1. Macros

A macro in C++ is a named piece of text that is expanded into other text during the preprocessing stage. Macros are often used to simplify code and make it more readable.

Eg. #define PI 3.14

This basically works like a constant value

The major difference between #define and const is, const creates a read-only variable (occupies space) whereas #define doesn't occupy space

2. Inline functions

An inline function in C++ is a function that is expanded in line when it is called. This means that the compiler copies the code of the function into the code of the calling function. This can improve the performance of the program by reducing the overhead of function calls.

Eg.
inline int square(int x){
    return x*x;
}

inline int max(int a, int b){
    return (a>b)?a:b;
}

inline void printArr(int* arr, int n){
    for (int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

How big inline functions can be?
-   There is no definitive answer to the question of how big inline functions can be in C++. The size of an inline function that can be inlined by the compiler depends on a number of factors, including the complexity of the function, the capabilities of the compiler, and the optimization settings that are used.

In general, inline functions should be kept as small as possible. This is because inline functions are expanded in line, which means that the code for the function is copied into the code of the calling function. This can increase the size of the program and can also make the code less portable.

As a rule of thumb, inline functions should be no more than 10-20 lines of code. However, there are cases where it may be necessary to have larger inline functions. For example, if a function is called frequently, it may be beneficial to inline it even if it is larger than 10-20 lines of code.

3. Default argument

Default value for a parameter can be provided, and if the function is called without providing a value for that parameter, the default value will be used.

Eg.
void printArr(int* arr, int size, int from=0){
    for (int i=from; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

* If the from-index is not provided by the user, the array will be printed from index 0

* Default parameters should be passed at the end of function parameters' list