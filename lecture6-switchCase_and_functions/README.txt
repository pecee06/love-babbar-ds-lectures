Switch statements are conditional statements like if-else, with the difference being that they can only handle discrete cases and not continuous ones

Syntax:
    switch (<expression>){
        case <const>:
            // code
            break;
        .
        .
        .
        default:
            // code
    }

<expression> can only be either int or char

If the value of the expression matches with the handled cases, then that block of code is executed. In case none of the handled cases matches, then the default block is executed. The default block is not mandatory

We add break statements at the end of each block of each case, this is done to prevent the execution of all the blocks of code below the block whose case is matched

* No need to add break at the end of default, as it's the last block of code in switch statements

Q. If we're inside an infinite loop and within it, we're using switch statement. The constraint being we can't use break statement outside the switch block, how to exit the loop?

Ans. We need to call a function exit(0), that comes with the stdlib.h header file. The compiler will terminate the program as soon as it encounters that function call

Functions: These are blocks of code that have its designate task, we give some input to it, the function processes the inputs and give us desired output

Functions implement the concept of DRY (Don't repeat yourself). They make the code more readable and makes it easy to debug

* There are predefined as well as user-defined functions

Syntax to define a function:
    <return-type> <function-identifier> (<parameters if any>){
        // code
        return <something of the return-type>;
    }

Syntax to call a function:
    * <function-identifier>(<arguments if any>);

* A function may or may not return some value

When we call a function, we pass some variables as arguments, those variables aren't actually passed into the function rather their copies are passed. This is known as pass by value

This means, whatever you do to the parameters of function in its definition, it's not going to effect the actual argument passed into it

But sometimes, we do need to alter the arguments passed into the function, then we have to call the function by giving reference to the arguments rather than the argument themselves. This is known as pass by reference