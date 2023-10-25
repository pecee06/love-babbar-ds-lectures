#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
};

class CircularQueue{
    Node* start;

    bool empty(){
        return (start->next == NULL);
    }
public:
    CircularQueue(){
        start = new Node;
        start->next = NULL;
    }

    void enqueue(int data){
        Node* last;
        (this->empty())?(last=start):(last=start->next);
        while(last->next != start->next){
            last = last->next;
        }
        Node* n = new Node;
        n->data = data;
        last->next = n;
        n->next = start->next;
    }
    void dequeue(){
        if (! this->empty()){
            Node* last = start->next;
            while(last->next != start->next){
                last = last->next;
            }
            Node* n = start->next;
            start->next = n->next;
            last->next = n->next;
            delete n;
        }
        else{
            cout<<"Queue is empty\n";
        }
    }
    void print(){
        Node* n = start->next;
        do{
            cout<<n->data<<" ";
            n = n->next;
        } while(n != start->next);
        cout<<endl;
    }
};

int main()
{
    CircularQueue q;

    q.enqueue(8);
    q.enqueue(18);
    q.enqueue(11);
    q.enqueue(31);
    q.enqueue(0);
    q.enqueue(19);

    q.dequeue();
    q.dequeue();

    q.print();
    
    return 0;
}
