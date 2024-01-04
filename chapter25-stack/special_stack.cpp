// Problem: Design a stack which implements getMin() in O(1) time & space

#include <iostream>
using namespace std;

class Stack{
    int* container;
    int size, top, min;

    bool empty(){
        return top == -1;
    }
    bool full(){
        return top == size-1;
    }

    int Min(int from, int to){
        int m = container[from], index = from;
        for (int i=from+1; i<=to; i++){
            if (container[i] < m){
                m = container[i];
                index = i;
            }
        }
        return index;
    }
public:
    Stack(int n){
        size = n;
        top = min = -1;
        container = new int[n];
    }

    void push(int key){
        if (this->full()) return;

        if (this->empty()){
            container[++top] = key;
            min = top;
        }
        else{
            container[++top] = key;
            if (key < container[min]) min = top;
        }
    }
    int pop(){
        if (this->empty()) return -1;
        
        if (min != top) return container[top--];

        min = Min(0,top-1);
        return container[top--];
    }
    int getMin(){
        if (!this->empty())
            return container[min];
        return -1;
    }
};

int main()
{
    Stack s(10);
    s.push(5);
    s.push(3);
    s.push(8);
    s.push(2);
    s.push(4);

    cout<<"Min = "<<s.getMin()<<endl;

    s.pop();
    s.pop();

    cout<<"Min = "<<s.getMin()<<endl;

    return 0;
}