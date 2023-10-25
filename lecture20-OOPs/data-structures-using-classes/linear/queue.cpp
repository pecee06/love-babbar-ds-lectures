#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
};

class Queue{
    Node* frontPtr;
    Node* rear;
    
    bool empty(){
        return (frontPtr->next == NULL);
    }
public:
    Queue(){
        frontPtr = new Node;
        rear = frontPtr;
        frontPtr->next = NULL;
    }

    void enqueue(int data){
        Node* n = new Node;
        n->data = data;
        rear->next = n;
        rear = n;
    }
    void dequeue(){
        if (! this->empty()){
            Node* n = frontPtr->next;
            frontPtr->next = n->next;
            delete n;
        }
        else{
            cout<<"Queue is empty\n";
        }
    }
    void print(){
        Node* n = frontPtr->next;
        while (n != NULL){
            cout<<n->data<<" ";
            n = n->next;
        }
        cout<<endl;
    }
};

int main()
{
    Queue q;
    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(1);
    q.enqueue(9);
    q.enqueue(15);

    q.dequeue();
    q.dequeue();

    q.print();
    
    return 0;
}
