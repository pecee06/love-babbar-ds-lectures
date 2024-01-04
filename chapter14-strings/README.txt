Strings are character arrays. This statement is partially true. Though internally they are same, there are some differences as well

Strings are precisely a sequence of characters which are implemented internally using character arrays. These character arrays are terminated with '\0' (NULL character - ASCII 0) to mark the end of string for the compiler. This means in a character array of size n+1, we can only store n characters explicitely, '\0' is a fixed character in any string

When we deal with strings, generally we don't use its character array implementation. Rather we use string as a separate datatype which is defined by the string class of C++, which provide us with many features &  methods which we can use upon objects created using string class

String class:
To use string datatype you have to #include <string>

Implementation-

Declare an empty string:
string str;

Declare and instantiate a string:
string str = "Hello World";
string str2("Hello World");

Create copy of a string:
string str2(str);

* One string can be asigned to another using '=' operator. This feature is not present in character arrays, you have to iterate through the entire array and update each character one by one

* Essentially strings are character arrays only, thus the individual characters can be accessed through their indices in constant time

* You can append a string to another string using "+=" operator

Imp function-

str.begin() -> returns an iterator to the first character of string
str.end() -> returns an iterator to the memory address next to '\0'
str.length() -> returns size of string
str.clear() -> clears the string
str.empty() -> returns a bool value of whether the string is empty or not
str.pop_back() -> deletes the last not NULL character from string
str.substr(<pos>,<len>) -> returns a substring of str of size <len> starting from index <pos>

str.front() -> returns the first character of string
str.back() -> returns the last not NULL character of string
* These 2 methods can be used as both getter and setter

str.replace(<index>,<span>,<str2>) -> replaces the substring of length <span> starting from <index> in str with str2
str.swap(<str2>) -> swap the 2 strings
str.find(<str2>) -> returns the index of the first character of the first match
str.rfind(<str2>) -> returns the index of the first character of the last match.
str.compare(<str2>) -> returns 0 if both strings are same, else returns either positive or negative number
str.find_first_of(<character sequence>) -> returns the index of the first character that matches any of the characters specified in its arguments
str.find_last_of(<character sequence>) -> returns the index of the last character that matches any of the characters specified in its arguments
str.find_first_not_of(<character sequence>) -> returns the index of the first character that does not match any of the characters specified in its arguments
str.find_last_not_of(<character sequence>) -> returns the index of the last character that does not match any of the characters specified in its arguments

* To take user input, we use cin in C++. The problem with cin is that, it stops execution as soon as it encounters space, tab or newline. Due to this reason only 1 word strings can be taken as input from users using cin. To tackle this problem we have getline(cin,str) method. It takes 2 arguments, cin tells the compiler that it has to accept a console input and the 2nd argument is the identifier of the string where we want to store that string input