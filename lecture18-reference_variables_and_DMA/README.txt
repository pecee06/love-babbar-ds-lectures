Reference of a varible means an identifier other than the original one, associated with the same memory location

To create a reference varible-
int a = 10;
int& b = a;

Now a & b both refer to the same memory location

Use of reference varibles-
When we pass an argument to a function, a copy of the passed value is created, which firstly occupies unneccessary extra space and secondly can't change the passed argument

To overcome these shortcommings we pass arguments by reference to functions

void increment(int& n){
    n++;
}

* We should not make the return type of a function as a reference since all the varibles created within function have local scope and their corresponding memory will get cleared anyway, after the function call
    On doing so, compiler throws a warning

Due to the same reason, we should not return a pointer from a function

DMA

There are 2 sections of memory - stack & heap
Stack is allocated at compile time, i.e., memory is reserved as per the need
All the management of memory stack is done by the compiler

But sometimes we need to allocate memory at runtime. For example, declaring an array of size that is entered by user. Now few compilers do allow to declare array of variable size but the problem being, if asked size of array is greater than the available space in stack, program will crash. So it's a bad practice

So to overcome this shortcomming, we do dynamic memory allocation, which allocates memory in heap (rest of the memory available in RAM)

"new" keyword is used to allocate memory dynamically. It returns a pointer to the memory address in heap

Eg. int* ptr = new int;
ptr is made in stack, but it stores the address of a memory location which is present in heap

To dynamically allocate an array-
int* arr = new int[<size>]

Now in heap, memory management has to be done manually
To free memory corresponding to a pointer, we use "delete" keyword

Eg. char* ptr = new char;
delete ptr;

int* arr = new int[10];
delete[] arr;