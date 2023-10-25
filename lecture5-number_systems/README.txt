The number system that we deal with in real world is decimal number system i.e., of base 10 but our computers can't really interpret those, thus we need to convert them into binary number system i.e., of base 2

To convert decimal to binary:
    * Keep dividing the number by 2 untill it reduces to 0, keep storing the remainders in each step and write them in reverse order

To convert binary to decimal:
    * Multiply corresponding bigits (starting from least significant bit to the most significant bit) with increasing powers of 2 (starting from 0) and add all to get decimal representation of binary number

We could convert any number system to any other, for example from base 4 to base 16, by first converting base 4 to base 10 and then converting the result into base 16, by adapting the algorithm of binary-decimal conversions as per the radix value

To get the least significant bit of a binary number, just & it with 1
To get rid of the least significant bit, right shift the binary numeber by 1 place