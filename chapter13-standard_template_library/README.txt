STL in C++ is a set of standard libraries which provide with classes containing multiple containers (data structures) and pre-defined algorithms
Eg. You can implement an array using the basic syntax, but if you implement using STL, you'll get a set of methods to run upon them and you don't have to code them explicitly

{DS}:

1. Array:

Arrays are fixed-size sequence containers: they hold a specific number of elements ordered in a strict linear sequence.

Properties-
Sequence:
Elements in sequence containers are ordered in a strict linear sequence. Individual elements are accessed by their position in this sequence.

Contiguous storage:
The elements are stored in contiguous memory locations, allowing constant time random access to elements. Pointers to an element can be offset to access other elements.

Fixed-size aggregate:
The container uses implicit constructors and destructors to allocate the required space statically. Its size is compile-time constant. No memory or time overhead.


Implementation-
You have to #include <array> before using array class of c++

array<int,4> arr = {1,2,3,4};
*Elements can be accessed in constant time just like an array declared using default syntax

Imp functions-
arr.begin() -> returns an iterator to the first element of the array
arr.end() -> returns an iterator to the last element of the array
arr.size() -> returns the size of the array (declared while Implementation)
arr.empty() -> returns bool value whether the given array is empty or not (empty array means the size of the array is 0)
arr.back() -> returns the last element of the array
arr.fill(<value>) -> initializes all the elements of the array with a particular value
arr.swap(<arr2>) -> swap the values of the 2 arrays (both arrays should be of same size)

2. Vector:

Vectors are sequence containers representing arrays that can change in size. Just like arrays, vectors use contiguous storage locations for their elements. When you insert more elements than vector's capacity then a new vector is created (of double the size of previous vector) in which all the elements already present in the original vector are copied and that memory is freed from heap

Properties-
Sequence:
Elements in sequence containers are ordered in a strict linear sequence. Individual elements are accessed by their position in this sequence.

Dynamic array:
Allows direct access to any element in the sequence, even through pointer arithmetics, and provides relatively fast addition/removal of elements at the end of the sequence.

Allocator-aware:
The container uses an allocator object to dynamically handle its storage needs.

Implementation-
You have to #include <vector> before using vector class of c++

creating an empty vector:
vector<int> v;

creating a vector of some initial size and garbage value:
vector<int> v(10);

creating a vector of some initial size and value:
vector<int> v(5,3); -> 5 blocks of memory each initilized with 3

creating a vector copy of another vector:
vector<int> v(<v2>);

copying one vector into another:
v = v2;

*Elements can be accessed using their indices

Imp functions-
v.begin() -> returns iterator to beginning
v.end() -> returns iterator to end
v.size() -> returns the number of elements stored in the vector
v.capacity() -> returns the capacity of vector
v.empty() -> returns bool value whether the given vector is empty or not
v.reserve(<n>) -> reallocates the vector and make its capacity = n (only if n >= initial capacity)
v.resize(<n>) -> reallocates the vector and make its size = n (if there are more than n elements already present in the vector then all the elements beyond n are destroyed)
v.shrink_to_fit() ->requests the container to reduce its capacity to fit its size.
v.front() -> returns the first element of the vector
v.back() -> returns the last element of the vector
v.push_back(<n>) -> adds n at the last position
v.pop_back() -> removes the element at the last position
v.emplace(<position-iterator>,<value>) -> create & insert <value> at the specified position
v.erase(<from-iterator>,<to-iterator>) -> remove elements from the vector from start iterator to end iterator
v.clear() -> deletes all the elements of the vector (the size is reduces to 0 and not the capacity)
v.swap(<v2>) -> swaps the 2 vectors

Relational operations between vectors-
v1 == v2 -> returns true if both vectors are same (sequence too has to be same)
v1 != v2 (equivalent: !(v1==v2)) -> returns true if the 2 vectors are different
v1<v2 -> compare the corresponding elements of both vectors sequencially, returns true or false at the first point of difference
v1>v2 (equivalent: v2<v1)
v1<=v2 (equivalent: !(v2<v1))
v1>=v2 (equivalent: !(v1<v2))

3. Forward List

Forward lists are implemented as singly-linked lists; Singly linked lists can store each of the elements they contain in different and unrelated storage locations. The ordering is kept by the association to each element of a link to the next element in the sequence.

Properties-
Sequence:
Elements in sequence containers are ordered in a strict linear sequence. Individual elements are accessed by their position in this sequence.

Linked list:
Each element keeps information on how to locate the next element, allowing constant time insert and erase operations after a specific element (even of entire ranges), but no direct random access.

Allocator-aware:
The container uses an allocator object to dynamically handle its storage needs.

Implementation-
You have to #include <forward_list> before using forward_list class of c++

creating an empty forward_list:
forward_list<int> fl;

creating a forward_list of some initial size and value:
forward_list<int> fl(5,3); -> 5 blocks of memory each initilized with 3

creating a forward_list copy of another forward_list:
forward_list<int> fl(<fl2>);

initializer_list constructor:
forward_list<int> fl = {1,2,3,4,5};

copying one forward_list into another:
fl = fl2;

Imp functions-
fl.before_begin() -> returns an iterator before the head iterator
fl.begin() -> returns the head iterator
fl.end() -> returns the tail iterator
fl.empty() -> returns bool value, whether the list is empty or not
fl.front() -> returns the first element of the list
fl.assign({elem1, elem2,..}) -> assigns new contents to the forward_list container, replacing its current contents, and modifying its size accordingly
fl.push_front(<n>) -> inserts n at the head position
fl.pop_front() -> deletes head element
fl.emplace_after(<position-iterator>,<n>) -> create & insert n after the specified position
{
fl.erase_after(<position-iterator>) -> deletes the element next to which iterator is pointing and returns iterator of that next element
fl.erase_after(<from-iterator>,<to-iterator>) -> deletes all the elements in the range (FROM+1) to TO
}
fl.swap(<fl2>) -> swaps one forward_list with other
fl.clear() -> removes all elements from the forward_list container (which are destroyed), and leaving the container with a size of 0
fl.remove(<n>) -> removes n from the list
fl.unique() -> removes duplicate elements from the list
fl.sort() -> sorts the list in ascending order
fl.reverse() -> reverses the list
fl.merge(<fl2>) -> merge two lists (returns an ordered list if given lists were already sorted)


4. List

List containers are implemented as doubly-linked lists; Doubly linked lists can store each of the elements they contain in different and unrelated storage locations. The ordering is kept internally by the association to each element of a link to the element preceding it and a link to the element following it.

Properties-
Sequence:
Elements in sequence containers are ordered in a strict linear sequence. Individual elements are accessed by their position in this sequence

Doubly-linked list:
Each element keeps information on how to locate the next and the previous elements, allowing constant time insert and erase operations before or after a specific element (even of entire ranges), but no direct random access

Allocator-aware:
The container uses an allocator object to dynamically handle its storage needs

This is same as forward_list, with some additional methods-
l.size() -> returns the size of list
l.back() -> returns the last element of list
l.push_back(<n>) -> inserts n at tail
l.pop_back() -> deletes the tail element
l.emplace(<position-iterator>,<n>) -> create & insert n at specified position

5. Stack

Stacks are a type of container adaptor, specifically designed to operate in a LIFO context (last-in first-out), where elements are inserted and extracted only from one end of the container.

Implementation-
You have to #include <stack> before using stack class of c++

stack<int> s;

Imp functions-
s.push(<n>) -> inserts n at the top of stack
s.pop() -> removes top element from stack
s.size() -> returns size of stack
s.empty() -> returns bool value of whether the stack is empty or not
s.top() -> access to topmost element
s.swap(<s2>) -> swap 2 stacks

6. Queue

Queues are a type of container adaptor, specifically designed to operate in a FIFO context (first-in first-out), where elements are inserted into one end of the container and extracted from the other.

Implementation-
You have to #include <queue> before using queue class of c++

queue<int> q;

Imp functions-
q.push(<n>) -> inserts n at the top of stack
q.pop() -> removes top element from stack
q.size() -> returns size of stack
q.empty() -> returns bool value of whether the stack is empty or not
q.front() -> access to first element
q.back() -> access to last element
q.swap(<q2>) -> swap 2 queues

Priority Queue-

Priority queues are a type of container adaptors, specifically designed such that its first element is always the greatest of the elements it contains, according to some strict weak ordering criterion. This context is similar to a heap, where elements can be inserted at any moment, and only the max heap element can be retrieved

Implementation-
priority_queue<int> pq;

Imp functions-
pq.push(<n>) -> inserts a n in the priority_queue
pq.pop() -> removes the element on top of the priority_queue (one with the highest value)
pq.size() -> returns size of priority_queue
pq.empty() -> returns bool value of whether the priority_queue is empty or not
pq.swap(<pq2>) -> swap 2 priority_queues

7. Deque

Double-ended queues are sequence containers with dynamic sizes that can be expanded or contracted on both ends (either its front or its back)

Properties-
Sequence:
Elements in sequence containers are ordered in a strict linear sequence. Individual elements are accessed by their position in this sequence

Dynamic array:
Generally implemented as a dynamic array, it allows direct access to any element in the sequence and provides relatively fast addition/removal of elements at the beginning or the end of the sequence

Allocator-aware:
The container uses an allocator object to dynamically handle its storage needs

Implementation-
You have to #include <deque> before using deque class of c++

creating an empty deque:
deque<int> dq;

creating a deque of some initial size and value:
deque<int> dq(5,3); -> 5 blocks of memory each initilized with 3

creating a deque copy of another deque:
deque<int> dq(<v2>);

copying one deque into another:
dq = dq2;

* Elements can be accessed using their indices

Imp functions-
dq.begin() -> returns iterator to beginning
dq.end() -> returns iterator to end
dq.size() -> returns the number of elements stored in the deque
dq.empty() -> returns bool value whether the given deque is empty or not
dq.resize(<n>) -> reallocates the deque and make its size = n (if there are more than n elements already present in the deque then all the elements beyond n are destroyed)
dq.shrink_to_fit() ->requests the container to reduce its capacity to fit its size.
dq.front() -> returns the first element of the deque
dq.back() -> returns the last element of the deque
dq.push_front(<n>) -> adds n at the beginning
dq.pop_front() -> deletes first element
dq.push_back(<n>) -> adds n at the last position
dq.pop_back() -> removes the element at the last position
dq.emplace(<position-iterator>,<value>) -> create & insert <value> at the specified position
dq.erase(<from-iterator>,<to-iterator>) -> remove elements from the deque from start iterator to end iterator
dq.clear() -> deletes all the elements of the deque
dq.swap(<dq2>) -> swaps the 2 deques

8. Set

Sets are containers that store unique elements following a specific order. In a set, the value of an element also identifies it (the value is itself the key, of type T), and each value must be unique. The value of the elements in a set cannot be modified once in the container (the elements are always const), but they can be inserted or removed from the container.

* Set by their definition in mathematics are unordered, but these sets are ordered in nature. For unordered sets we have another data structure unordered_set

* Sets are typically implemented as binary search trees.

Properties-
Associative:
Elements in associative containers are referenced by their key and not by their absolute position in the container.

Ordered:
The elements in the container follow a strict order at all times. All inserted elements are given a position in this order.

Set:
The value of an element is also the key used to identify it.

Unique keys:
No two elements in the container can have equivalent keys.

Allocator-aware:
The container uses an allocator object to dynamically handle its storage needs.

Implementation-
You have to #include <set> before using set class of c++

creating an empty set:
set<int> s;

creating a set copy of another set:
set<int> s(<s2>);

copying one set into another:
s = s2;

Imp functions-
s.begin() -> returns iterator to beginning
s.end() -> returns iterator to end
s.size() -> returns the number of elements stored in the set
s.empty() -> returns bool value whether the given set is empty or not
s.insert(<position-iterator>,<value>) -> inserts <value> at the specified position
s.erase(<from-iterator>,<to-iterator>) -> remove elements from the set from start iterator to end iterator
s.clear() -> delete all the elements of the set
s.swap(<s2>) -> swaps the 2 sets
s.find(<n>) -> returns iterator to n
s.count(<n>) -> returns 1 if n is found else 0
s.lower_bound() -> returns iterator to least value element
s.upper_bound() -> returns iterator to max value element

9. Map

Maps are associative containers that store elements formed by a combination of a key value and a mapped value, following a specific order. In a map, the key values are generally used to sort and uniquely identify the elements, while the mapped values store the content associated to this key

* Maps are typically implemented as binary search trees

* Elements can be accessed using their keys (like indices)

Properties-
Associative:
Elements in associative containers are referenced by their key and not by their absolute position in the container

Ordered:
The elements in the container follow a strict order at all times. All inserted elements are given a position in this order

Map:
Each element associates a key to a mapped value: Keys are meant to identify the elements whose main content is the mapped value

Unique keys:
No two elements in the container can have equivalent keys

Allocator-aware:
The container uses an allocator object to dynamically handle its storage needs

Implementation-
You have to #include <map> before using map class of c++

map<char,int> mp;
mp['a'] = 1;
mp['b'] = 10;
mp['c'] = 111;

To instantiate a map with key-value pairs of some other map:
map<char,int> mp(<mp2>);

To copy one map into another:
mp1 = mp2

Imp functions-
mp.begin() -> returns iterator to first object
mp.end() -> returns iterator to last object
mp.size() -> returns container size
mp.empty() -> returns bool value whether the given map is empty or not

mp.erase(<position-iterator>) -> removes object at position-iterator
mp.erase(<key>) -> removes object with specified key

mp.clear() -> delete all the elements of the map
mp.swap(<mp2>) -> swaps the 2 maps

{Algo}:

The header <algorithm> defines a collection of functions especially designed to be used on containers of elements like array, queue, map, etc.

You have to #include <algorithm> to use those algos