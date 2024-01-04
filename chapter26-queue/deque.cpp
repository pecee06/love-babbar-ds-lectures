#include <iostream>
using namespace std;

class Deque{
    class Node{
    public:
        int key;
        Node *prev, *next;
    };
    Node *front, *rear;

    Node* createNode(int key){
        Node* n = new Node;
        n->key = key;
        return n;
    }
public:
    Deque(){
        front = rear = NULL;
    }

    bool empty(){
        return !front;
    }
    void push_front(int key){
        if (this->empty()){
            front = createNode(key);
            rear = front;
            rear->prev = rear->next = NULL;
        }
        else{
            Node* n = createNode(key);
            n->prev = NULL;
            n->next = front;
            front->prev = n;
            front = n;
        }
    }
    void push_back(int key){
        if (this->empty()){
            front = createNode(key);
            rear = front;
            rear->prev = rear->next = NULL;
        }
        else{
            Node* n = createNode(key);
            n->prev = rear;
            n->next = NULL;
            rear->next = n;
            rear = n;
        }
    }
    void pop_front(){
        if (!this->empty()){
            Node* popped = front;
            if (front == rear) front = rear = NULL;
            else{
                front = front->next;
                front->prev = NULL;
            }
            delete popped;
        }
    }
    void pop_back(){
        if (!this->empty()){
            Node* popped = rear;
            if (front == rear) front = rear = NULL;
            else{
                rear = rear->prev;
                rear->next = NULL;
            }
            delete popped;
        }
    }
    int first(){
        if (this->empty()) return -1;
        return front->key;
    }
    int last(){
        if (this->empty()) return -1;
        return rear->key;
    }

    ~Deque(){
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
    Deque q;
    
    q.push_front(10);
    q.push_front(26);
    q.push_front(5);

    q.push_back(1);
    q.push_back(2);
    q.push_back(8);

    q.pop_back();
    q.pop_front();

    while (!q.empty()){
        cout<<q.last()<<endl;
        q.pop_back();
    }

    return 0;
}