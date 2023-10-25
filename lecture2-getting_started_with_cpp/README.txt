To give instructions to a computer to do a certain task, we use a programming language

Now computers on their own do not understand these high-level(human readable) languages like C++, we need a translator (called compiler) which converts all this high-level code into low-level machine code (binary)

For C++ we use g++ compiler to compile our code into a machine executable file (.exe on windows, .o on linux)

To do so in the terminal:
g++ <file-name>.cpp -o <alias>

Compilers can also spot compile time errors (syntax errors, semantic errors)
At execution we can spot the runtime errors as well

* No way to spot logical errors, you have to debug your code