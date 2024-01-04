#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
};

class Deque{
    Node* frontPtr;
    Node* rear;

    bool empty(){
        return (frontPtr->next == NULL);
    }
public:
    Deque(){
        frontPtr = new Node;
        frontPtr->next = NULL;
        rear = frontPtr;
    }

    void enqueue(int data){
        Node* n = new Node;
        n->data = data;
        rear->next = n;
        rear = n;
        n->next = NULL;
    }
    void enqueueFront(int data){
        Node* n = new Node;
        n->next = frontPtr->next;
        frontPtr->next = n;
        n->data = data;
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
    void dequeueBack(){
        if (! this->empty()){
            Node* n = frontPtr->next;
            while (n->next !=  rear){
                n = n->next;
            }
            rear = n;
            delete n->next;
            rear->next = NULL;
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
    Deque q;
    
    q.enqueue(24);
    q.enqueue(6);
    q.enqueueFront(14);
    q.print();

    q.dequeue();

    q.enqueue(67);
    q.dequeueBack();

    q.print();
    
    return 0;
}
