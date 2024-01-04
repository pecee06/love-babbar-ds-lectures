Biwise operators are operators which perform operation on operands bit by bit

4 bitwise operators are present:
    * & (AND)   -> (1,1)=>1, else 0
    * | (OR)    -> (0,0)=>0, else 1
    * ~ (COMPLIMENT) -> 0=>1, 1=>0 {unary}
    * ^ (XOR)   -> (same)=>0, (different)=>1
    * << (left shift)
    * >> (right shift)

* ~n (n -> integer) = -(n+1)
* m<<n (m,n -> integers) = m*(pow(2,n))
* m>>n (m,n -> integers) = m/(pow(2,n))

Scope of a variable is the block of code from which a variable can be accessed

Variables defined directly inside the main block, are global variables, and can be accessed from anywhere
Other variables have local scope and can be accessed in the block in which they're defined or the blocks within that

In C++, unlike mathematics BODMAS rule isn't followed, so here we have defined the precedence and associativity for each operator, to avoid confusion

precedence -> weightage of an operator (higher the weightage, operation will be performed earlier)
associativity -> In what way (left to right or right to left), the operation will be performed in order to avoid confusion among the operators with same precedence

But rather than memorizing all these precedences and associativities, use brackets