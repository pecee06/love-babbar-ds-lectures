When we instantiate a variable, a memory block gets reserved and the value is stored in it. The compiler can't track the location of a variable by its name, so it maintains a data structure called as symbol table which basically stores information about the names of variables, functions, classes, and other entities in a program.

When the compiler encounters the name of a variable, it looks up the variable in the symbol table to find its memory location.

Memory addresses are hexadecimal numbers (base 16) with a "0x" prefix

To access address of a memory location, we have '&' (address of) operator

Since we can access address of a variable, we may need to store it as well. The datatype which can store such values is called pointer

If it stores the address of an integer, it's called integer pointer, if it stores the address of a character, it's called character pointer and so on

* A pointer of a particular type can't store the address of a variable of another type

* Always initialize a pointer while creating it, else it would be a dangling pointer which could be pointing to any memory location, which may or may not be among the memory blocks accessible to your program

To dereference a pointer (get value whose address it's storing), we have '*' (value at) operator

* Any type of pointer occupy 4 bytes

Typecasting of pointers-

Typecasting pointer of one type into another is a dangerous operation

Eg. if int* is typecasted to char*, the new pointer still holds the address of the original integer variable but when you dereference it, it will give you the character corresponding to an 8 bit number as per ASCII. If the integer value cannot be contained in 8 bits then all the excess bits are discarded

Eg. If char* is typecasted to int*, the new pointer still holds the address of the original character variable but when you dereference it, it will convert the character into binary as per ASCII and since integers are 32 bit values but characters are 8 bit values, all the bits (after first 8 bits) are filled with garbage binary values, which may give any integer as final answer


Incrementing pointers-

If you increment a pointer, it points to the next memory address. Next memory address depends upon type of pointer.
Eg. int* when gets incremented, it points to (current memory address + sizeof(int)), but when char* gets incremented, it points to (current memory address + sizeof(char))

Arrays as pointers-

When we declare an array, the name of the array is a pointer to the first element of it. Since in arrays, elements are stored in contiguous memory locations, we can access them by incrementing and dereferencing

When we access array elements using indices, internally compiler calculates it using pointers only
arr[i] = *(arr+i)
This means, for compiler i[arr] is same as arr[i]

Still, after many similarities, arrays and pointers are not the same thing

- Arrays are containers which can store multiple values within it in contiguous locations, while pointers can only store address of a variable

- Arrays are initialized at compile time (with garbage value), but pointers are initialized at run time

- sizeof(arr) = {no of elements in array * sizeof(each-element)} while sizeof(ptr) is fixed (4 bytes)

- &arr and arr are same thing but if ptr = arr, then &ptr and ptr are different

- arr can't be incremented as it in the symbol table, arr is mapped to address of first element of a container. But on the other hand pointers can be incremented

Character arrays-

The basic difference between int arrays and char arrays is that, character arrays are terminated with a '\0' character

character arrays can also be initialized as a string
Eg. char str[] = "dsa";

cout & cin are implemented differently for character arrays or pointers

Eg. int arr[] = {1,2,3,4};
    cout<<arr; -> will give the memory address of arr[0]

    char str[] = "hello";
    cout<<str; -> will give the entire string (hello) as output
    char* c = str;
    cout<<c; -> will still give the entire string as output

    char str[] = {'h','e','l','l','o'};
    cout<<str; -> this will print hello followed by some garbage characters till the compiler encounters '\0'
    Thus it is advised to terminate your character array with '\0' while instatiating
    Eg. char str[] = {'h','e','l','l','o','\0'};

Still, str in itself is a pointer only, to the first element of character array
Eg. cout<<*str; -> will give first character of str as output
Eg. cout<<*(str+1); -> will give second character of str as output

Whenever a character array is initialized as a cstring, internally, it is first stored in a temporary memory location then a contiguous block is allocated where these characters are copied
Thus it is advised to not initialize a character array like char* str = "text", this will again create the problem of dangling pointer
Better do it like char str[] = "text"

Pointers and functions-

If pointers as passed as functional arguments then inside its call, a copy of passed pointer is generated which also stores the address stored by the original pointer, this way both the pointers are pointer to original variable only, thus we can make changes to it inside function

Reference of variables can also be passed directly into a function
Eg. void f(int& a){
    // code
}
This function takes a reference argument, which means even if you pass the value of variable, it will not create a copy of that, rather it will recieve the original variable only

The difference between the two is:
Whatever is passed as a functional argument, its copy is created inside the function call and any changes made to it, won't be reflected. But when you send the reference of something as a functional argument, no new copy is generated, rather it accesses the original variable

When an array is passed as a functional argument, internally a pointer to the first element of the array is passed

Double pointers-

These are pointer to pointers, they basically store the address of a pointer which itself is storing the address of a variable

To get the value of variable from its double pointer, you need to dereference it twice

We use double pointers for mainly two purposes:
- Changing pointer to a variable
- Allocate memory for 2D arrays

Eg. int arr[3][2] = {
        {0,2},
        {4,5},
        {7,8}
    };
    
    int (*ptr)[2] = arr; -> ptr will store the address of first array (which in turn is the address of pointer to first element of first array)
    
    cout<<**(ptr+1); -> this will give 4 as output
    cout<<*(*ptr+1); -> this will give 2 as output
    cout<<**ptr+1; -> this will give 1 as output