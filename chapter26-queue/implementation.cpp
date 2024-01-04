#include <iostream>
using namespace std;

class Queue{
    class Node{
    public:
        int key;
        Node* next;
    };
    Node *front, *rear;

    Node* createNode(int key){
        Node* n = new Node;
        n->key = key;
        n->next = NULL;
        return n;
    }
public:
    Queue(){
        front = rear = NULL;
    }

    bool empty(){
        return front == NULL;
    }
    void enqueue(int key){
        if (this->empty()){
            front = createNode(key);
            rear =  front;
        }
        else{
            Node* n = createNode(key);
            rear->next = n;
            rear = n;
        }
    }
    void dequeue(){
        if (!this->empty()){
            Node* popped = front;
            if (front == rear) front = rear = NULL;
            else front = front->next;
            delete popped;
        }
    }
    int first(){
        if (!this->empty()) return front->key;
        return -1;
    }

    ~Queue(){
        Node* n = front;
        while (n){
            Node* popped = n;
            n = n->next;
            delete popped;
        }
    }
};

int main()
{
    Queue q;
    q.enqueue(5);
    q.enqueue(4);
    q.enqueue(3);
    q.enqueue(2);
    q.enqueue(1);

    while (!q.empty()){
        cout<<q.first()<<endl;
        q.dequeue();
    }

    return 0;
}