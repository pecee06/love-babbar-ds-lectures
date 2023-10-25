#include <iostream>
#include <string>
using namespace std;

class Human{
    protected:
        // Attributes
        string name;
        float height;   // in metres
        float weight;   // in KG
        string eyeColor;
    public:
        static int noOfPeople;  // Static data members are to be initialized after class definition
        static int peopleCount(){
            return noOfPeople;
        }

        // Constructor
        Human(string name){
            noOfPeople++;
            this->name = name;
        }

        // Methods
        void setHeight(float height){
            this->height = height;
        }
        void setWeight(float weight){
            this->weight = weight;
        }
        void setEyeColor(string eyeColor){
            this->eyeColor = eyeColor;
        }
        string getName(){
            return this->name;
        }
        float getHeight(){
            return this->height;
        }
        float getWeight(){
            return this->weight;
        }
        string getEyeColor(){
            return this->eyeColor;
        }
};
int Human::noOfPeople = 0;

class Male:public Human{
    int beardSize;
    public:
        Male(string name):Human(name){}
        // By default the default-constructor of the parent class is called when an object of child class is created. In case there's no default-constructor in parent class and non-parameterized constructor too ain't explicitely defined, then a run-time error will be thrown
        // To overcome this problem, we explicitely called the parameterized constructor of the super class

        void setBeardSize(int beardName){
            this->beardSize = beardSize;
        }
        int getBeardSize(){
            return this->beardSize;
        }
};

class OrderedPair{
    int x,y;
    public:
        OrderedPair(int x, int y){
            this->x = x;
            this->y = y;
        }
        OrderedPair operator+ (OrderedPair& obj){
            int a = this->x + obj.x;
            int b = this->y + obj.y;
            OrderedPair newObj(a,b);
            return newObj;
        }
        void getPair(){
            cout<<"("<<x<<","<<y<<")\n";
        }
};

class Dog{
    int legs;
    public:
        Dog(int legs){
            this->legs = legs;
        }
        void speak(){
            cout<<"Bhau Bhau\n";
        }
        int getLegs(){
            return this->legs;
        }
};

class Brian:public Dog{
    public:
        Brian(int legs):Dog(legs){}
        void speak(){
            cout<<"Hi, my name is Brian Griffin\n";
        }
};

int main(int argc, char const *argv[])
{
    /*
    Human h1("Priyanshu");
    Human h2("Om");

    cout<<Human::peopleCount()<<endl;

    Human h3("Suhane");
    Human h4("Yash");

    cout<<Human::peopleCount()<<endl;

    h1.setEyeColor("black");
    cout<<h1.getEyeColor()<<endl;
    cout<<h2.getWeight()<<endl; // Accessing an attribute before setting it (garbage value is returned)

    Male m1("Kullu");
    cout<<Human::peopleCount()<<endl;
    m1.setWeight(64);
    m1.setBeardSize(2);
    cout<<m1.getName()<<"'s weight is "<<m1.getWeight()<<" KG\n";
    */

    /*
    OrderedPair op1(5,6);
    OrderedPair op2(-2,0);

    OrderedPair op3 = op1+op2;
    op3.getPair();
    */

    Dog d(5);
    d.speak();
    
    Brian obj(4);
    cout<<obj.getLegs()<<endl;
    obj.speak();
    
    return 0;
}
