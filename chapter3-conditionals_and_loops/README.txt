Conditional statements help in decision making process

Syntax:
if (condition){
    // do something
}
else{
    // do something else
}

The shorthand for writing this is the ternary operator
(condition) ? (// do something if-true):(// do something else otherwise);

Ternary operator has a bad readability, thus we avoid its usage

There's an else-if block as well, which is used to apply mutiple conditions

To deal with discrete conditions we have switch statements

Syntax:
switch(<identifier>){
    case <value>:
        // code
       break;
    case <value2>:
        // code
       break;
    default:
        // code
}

Loops are used to do a task repeatedly

There are 3 types of loops in C++:
    * for
    * for-in (range based loop)
    * while
    * do-while

Syntax:
1. for (initiation;condition;updation){
	// code
}
2. for (range_declaration : range_expression){
	// code
}
3. while (condition){
	// code
}
4. do{
	// code
} while (condition);

for loops are used when it's known beforehand how many times we need to iterate
for-in loops are used to ietrate over a sequence (arrays,vectors,etc.)
while loops are used to iterate till a certain condition is true
do-while loops are like while loop which run at least once