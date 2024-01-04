Object oriented programming is a programming paradigm in which we use classes and objects to make the program as close as possible to the real world

Class: User defined datatype
Object: Any entity with attributes and functions. Precisely, an instance of a class

Implementation:
class <className>{
    // attributes
    // methods
};

// Creating object from a class
<className> <objectName>;

* Memory corresponding to data members of a class is only allocated when an object of that class is instantiated
* Member functions however, are defined only once, even before object instantiation

* If an empty class is instantiated then too 1 byte memory is allocated to keep track of the object

* Total memory allocated on object instantiation is not equal to the sum of sizes of attributes that are defined within it, many a times. There's a concept called as word size which is the amount of data a CPU's internal data registers can hold and process at one time. Modern desktop computers have 64-bit words. Which leads to data structure padding (addition of some empty bytes of memory in the structure)

* We can either create a class in the same file in which we'll be creating its object or in some other file and include it using preprocessor directive

Now the scope of properties of a class depends upon the access modifier under which it is defined

There are 3 access modifiers out there:
    * private: properties can only be accessed within the class
    * protected
    * public: properties can be accessed from anywhere (both within and outside the class)

* Default access modifier is private

properties of a class can be accessed from its object using the '.' (dot) operator

Now usually, we keep all attributes of a class as private and define their getters and setters under the public access modifier

We can also create object dynamically (in heap) using the "new" keyword

When we do so, we get a pointer to the object. To access class' properties using that, we use "->" (arrow) operator

Whenever we create an object of a class, a constructor gets called (automatically). We can either explicitely define the constructor to a class, else the compiler creates an implicite constructor (empty). In case we define a constructor explicitely, no implicite creation of constructor takes place

* Constructors don't have any return type and they can either be default (either no parameter or default arguments) or parameterized

Defining a constructor:
<className>(){
    // code
}

* Constructors must be defined under public access domain

"this" keyword-

"this" is a pointer to current object
As soon as an object is instantiated, "this" gets its value

If we pass an object as an argument to a constructor of another object, a default copy-constructor is created in the class, which copies the passed object into current object

* We can also explicitely define copy-constructor. While doing so, a reference to the object should be expected by the copy-constructor, else it traps in an infinite recursion

* Once the copy-constructor is explicitely defined, no implicite copy-constructor is created by the compiler

The problem with implicite copy-constructors is that, they create a shallow copy of object. Meaning, the new object is just another reference to the passed object, no new memory gets allocated for the new object. With explicitely copy-constructors this ain't a problem

When an object is assigned to another object using '=' operator, the property instances of the object at left side of '=' are updated with those of the obje' at right side of '='

Destructors-

It is called when memory corresponding to an object is freed. For static objects, it is called automatically, for dynamic ones, we have to call them manually using "delete" keyword

Destructors too, like constructors are implicitely created by the compiler, though we can explicitely define them as well

Defining a destructor:
    ~<className>{
        // code
    }

* Just like constructors, they too don't have any return type, their name must be same as that of class. To distinguish it from the constructor, '~' (tilde) is prefixed to the destructor

* Explicite destructors shouldn't have any parameter

const objects-

We can declare an object as const while instantiation, but then it will only be able to access const methods of its class

We can also define const data members, but to initialize them we need to use initializer list
Eg.
class Point {
const int x;
const int y;
public:
    Point(int i = 0, int j = 0):x(i), y(j) {}

    // const methods
    int getX() const {
        return x;
    }
    int getY() const {
        return y;
    }
};

Initializer list is passed with the constructor followed by a ':' (colon)

Static data members and member functions-

Attributes and methods, prefixed with "static" keyword are static in nature, i.e., they are declared once, their lifetime is throughout the program and they belong to the class and not to a particlar object

* Static member functions can only access static data members

To access static data members:
<datatype> <className>::<data member>;

To access static member functions:
<className>::<member function>();

Pillars of OOPs-

1. Encapsulation: Wrapping of data members & member functions in a class

Fully Encapsulated Class -> All the data members are private

Why encapsulation? -> It allows data hiding, provide security, code reusability

2. Inheritance: It allows a class to inherit the properties and behaviors of another class. This is known as the IS-A relationship.
    Eg., a Dog class can inherit from an Animal class, because a Dog is an Animal

Syntax:
class <className>:<access specifier> <super class>{
    // definition
};

Now what all data members and member functions will be accessible to the child class depends upon the combination of access specifiers used

members-of-super-class  inherited-as    scope-in-derived-class
----------------------  ------------    -------------------
public                  public          public
public                  private         private
public                  protected       protected

private                 public          not accessible
private                 private         not accessible
private                 protected       not accessible

protected               public          protected
protected               private         private
protected               protected       protected

Protected members are those which can be accessed within the class in which they're defined and in their children classes

Abstract Class: An abstract class in C++ is a class that has at least one pure virtual function. It is solely created to be used as a base class to other classes. We can't create its object

A pure virtual function is a virtual function (It is a member function that is declared within a base class and is redefined (overridden) by a derived class) for which we don't provide an implementation, we must override that method in the derived class

A pure virtual function is decalred like->
    virtual <return-type> <f-name>() = 0;

* If we don't override the pure virtual functions in the derived class, the derived class will also become an abstract class

Types of inheritance-

(a) Single: It is a type of inheritance in which a derived class inherits from only one base class

(b) Multi Level: It is a type of inheritance in which a derived class inherits from another derived class. This means that the derived class inherits the properties and behaviors of both of its base classes

(c) Multiple: It is a type of inheritance in which a derived class inherits from two or more base classes
class <className>: <access modifier> <parentClass-1>, <access modifier> <parentClass-2>{
    // definition
}

(d) Hierarchical: It is a type of inheritance in which a derived class inherits from a single base class. The derived class can then be parent to other classes, creating a hierarchy of classes
The main difference between multilevel inheritance and hierarchical inheritance is that multilevel inheritance creates a linear hierarchy of classes, while hierarchical inheritance creates a tree-like hierarchy of classes

(e) Hybrid: It is a type of inheritance that combines two or more different types of inheritance

Resolving ambiguity:
If a class inherits multiple classes (multiple inheritance) and they contain methods of same name (same parameters as well), then to resolve this ambiguity of choosing an instance of a method of an object of child class, scope resolution operator is used with the parent class whose method is to be called

Eg.
class A{
    // definition
};
class B{
    // definition
};
class C:public A, public B{
    // defintion
};

main(){
    C obj;
    obj.A::f();
    obj.B::f();
}

In case of hierarchical inheritance, say the derived class is inherited from 2 classes and both of them were derived from a single class. This will create ambiguity for compiler in choosing between same members (of grandparent) from 2 base classes

For handling this, we use virtual base classes
Virtual base class is a way of preventing multiple instances of a given class from appearing in an inheritance hierarchy when using multiple inheritance

Eg.
class A{
    // definition
};
class B:virtual public A{
    // definition
};
class C:virtual public A{
    // defintion
};
class D:public A, public B{
    // definition
};

3. Polymorphism-

Poly means many and Morph means forms. So polymorphism is all about multiple forms of a single entity
Eg. I am an individual, my role in college is different from my role in hostel, which in turn is different from that in my home

Types of polymorphism:

(a) Compile time polymorphism: It is a type of polymorphism that is resolved by the compiler at compile time. This means that the compiler determines which method to call at compile time, based on the type of object that is being used. It is achieved using method overloading and operator overloading

Method overloading: This allows a class to have multiple member functions with same name but different parameters. Their return type may or may not be different

Eg.
class A{
public:
    void greet(){
        cout<<"Hello\n";
    }
    void greet(string name){
        cout<<"Hello "<<name<<endl;
    }
};

Operator overloading: It is a feature of object-oriented programming that allows us to redefine the behavior of operators with objects. The compiler will determine which behavior to use based on the types of the operands

Eg.
class Complex{
public:
    int x,y;
    Complex(int x, int y){
        this->x = x;
        this->y = y;
    }
    void operator+(Complex z){
        int real = this->x + z.x;
        int img = this->y + z.y;
        cout<<real<<" + i"<<img<<endl;
    }
};

(b) Run time polymorphism: It is a type of polymorphism that is resolved at runtime. This means that the compiler doesn't know which method to call beforehand. It is achieved using method overriding.

Method overriding: It is a feature of object-oriented programming that allows a subclass to provide its own implementation of a method that is defined in its superclass

* We use virtual functions in superclass to mark it for compiler, as it could be overridden eventually

* Mentioning a method as "virtual" in a base class won't constraint you to override it in the derived class. It basically allows to call a subclass member method (also present in super class) with a pointer of type superclass

Eg.
class Base{
public:
    virtual void print(){
        cout <<"Base\n";
    }
};

class Derived :public Base{
public:
    void print(){
        cout <<"Derived\n";
    }
};

Derived d;
Base* ptr = &d;
ptr->print();    // will print "Derived"

Base b;
ptr = &b;
ptr->print();    // will print "Base"

4. Abstraction-

It means implementation hiding, basically showing only the neccessary details to the user

Real life example, When we chat on WhatsApp, we know that once we type the message in the message box and press the place icon, it will be sent. But do we know how exactly this thing is happening, how the app handles this request, how message is sent over the internet? We don't, and neither we need to. That's abstraction

5. Data Hiding-

It’s an OOP technique of hiding internal object details, i.e., data members. This guarantees restricted data access to class members and maintains object integrity

In terms of access specifiers, private, public, and protected are three types of protection/access specifiers available within a class

Private members of a class can be accessed by the class itself or a friend class or function

A friend class is a class that can access the private and protected members of another class in which it is declared as a friend
This is sometimes useful when we want to allow a particular class to access the private and protected members of another class

Eg.
class B;    // initial declaration
class A{
    // private members
public:
    // public members
    friend class B; // After this declaration, even private members of class A can be accessed by objects of class B
};

class B{
    // definition
}

A friend function is a function that is specified outside a class but has the ability to access the class members' protected and private data
A friend function is a non-member function or ordinary function of a class, which is declared as a friend using the keyword friend inside the class
By declaring a function as a friend, all the access permissions are given to the function