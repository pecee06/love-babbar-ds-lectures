Asymptotic notations are mathematical tools that help us compare the growth rates of different functions. They are useful for analyzing the efficiency and complexity of algorithms, especially when the input size is large. There are three main types of asymptotic notations: big O, big omega, and big theta.

Big O notation gives an upper bound on the growth rate of a function. It tells us the maximum amount of time or space that an algorithm can take in the worst case scenario. For example, if f(n) = 2n + 3, then f(n) is O(n), because f(n) grows at most as fast as a linear function of n.

Big omega notation gives a lower bound on the growth rate of a function. It tells us the minimum amount of time or space that an algorithm can take in the best case scenario. For example, if f(n) = 2n + 3, then f(n) is omega(n), because f(n) grows at least as fast as a linear function of n.

Big theta notation gives a tight bound on the growth rate of a function. It tells us the exact order of magnitude of an algorithm in the average case scenario. For example, if f(n) = 2n + 3, then f(n) is theta(n), because f(n) grows exactly as fast as a linear function of n.

Asymptotic notations help us compare and optimize algorithms based on their performance and resource consumption. They allow us to ignore constant factors and focus on the dominant terms that affect the scalability and efficiency of algorithms.

This mathematical tool is used for figuring out time & space complexities of programs

Time complexity: It is the amount of time taken by a program as a function of input size "n"
Space complexity: It is the amount of extra space that is consumed by the program in the runtime, as a function of input size "n"

* Most modern machines can perform 10^8 operations in a second nowadays, so accordingly as per the given constraints choose your algorithm wisely, so that time limit should not exceed