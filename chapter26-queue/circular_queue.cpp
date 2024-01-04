#include <iostream>
using namespace std;

class CircularQueue{
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
    CircularQueue(){
        front = rear = NULL;
    }

    bool empty(){
        return front == NULL;
    }
    void enqueue(int key){
        if (this->empty()){
            front = createNode(key);
            rear = front;
            rear->next = front;
        }
        else{
            Node* n = createNode(key);
            rear->next = n;
            n->next = front;
            rear = n;
        }
    }
    void dequeue(){
        if (!this->empty()){
            Node* popped = front;
            if (front == rear) front = rear = NULL;
            else{
                front = front->next;
                rear->next = front;
            }
            delete popped;
        }
    }
    int first(){
        if (this->empty()) return -1;
        return front->key;
    }

    ~CircularQueue(){
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
    CircularQueue q;
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