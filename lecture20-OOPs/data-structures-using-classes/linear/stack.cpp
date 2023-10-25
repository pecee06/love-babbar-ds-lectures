#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
};

class Stack{
    Node* topPtr;

    bool empty(){
        return (topPtr->next == NULL);
    }
public:
    Stack(){
        topPtr = new Node;
        topPtr->next = NULL;
    }

    void push(int data){
        Node* n = new Node;
        n->data = data;
        n->next = topPtr->next;
        topPtr->next = n;
    }
    void pop(){
        if (! this->empty()){
            Node* n = topPtr->next;
            topPtr->next = n->next;
            delete n;
        }
        else{
            cout<<"Stack underflow\n";
        }
    }
    void print(){
        Node* n = topPtr->next;
        while (n != NULL){
            cout<<n->data<<"\n";
            n = n->next;
        }
    }
};

int main()
{
    Stack s;
    s.push(5);
    s.push(10);
    s.push(2);
    s.push(7);

    s.pop();

    s.print();
    
    return 0;
}
