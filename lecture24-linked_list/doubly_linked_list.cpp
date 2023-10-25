#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* prev;
    Node* next;
};

class DList{
    Node* headPtr;
    Node* tail;

    bool empty(){
        return (headPtr->next == NULL);
    }
    void del(Node* n){
        if (n == NULL){
            return;
        }
        del(n->next);
        delete n;
    }
public:
    DList(){
        headPtr = new Node;
        headPtr->prev = NULL;
        headPtr->next = NULL;
        tail = headPtr;
    }

    void addHead(int data){
        Node* n = new Node;
        n->data = data;
        if (this->empty()) tail = n;
        n->prev = headPtr;
        n->next = headPtr->next;
        headPtr->next = n;
    }
    void addTail(int data){
        Node* n = new Node;
        n->data = data;
        tail->next = n;
        n->prev = tail;
        n->next = NULL;
        tail = n;
    }
    void insert(int pos, int data){
        Node* temp = headPtr;
        for (register int i=1; i<pos; i++){
            if (temp != tail)
                temp = temp->next;
        }
        Node* n = new Node;
        n->data = data;
        n->next = temp->next;
        n->prev = temp;
        temp->next = n;
        if (temp == tail) tail = n;
    }
    void delHead(){
        Node* n = headPtr->next;
        headPtr->next = n->next;
        n->next->prev = headPtr;
        free(n);
    }
    void delTail(){
        Node* n = tail->prev;
        n->next = NULL;
        free(tail);
        tail = n;
    }
    void remove(int elem){
        if (! this->empty()){
            Node* n = headPtr->next;
            bool found = false;
            while (n != NULL){
                if (n->data == elem){
                    found = true;
                    break;
                }
                n = n->next;
            }
            if (found){
                Node* previous = n->prev;
                previous->next = n->next;
                if (n == tail) {
                    tail = previous;
                }
                else{
                    n->next->prev = previous;
                }
                delete n;
            }
            else{
                cout<<"Element not present in list\n";
            }
        }
        else{
            cout<<"List is empty\n";
        }
    }
    void print(){
        Node* n = headPtr->next;
        while (n != NULL){
            cout<<n->data<<" ";
            n = n->next;
        }
        cout<<endl;
    }

    ~DList(){
        del(headPtr);
    }
};

int main()
{
    DList l;

    l.addHead(44);
    l.addTail(14);
    l.addHead(21);
    l.insert(2,67);
    l.insert(2,24);

    l.delHead();
    l.delTail();
    l.addTail(69);
    l.remove(21);

    l.print();
    
    return 0;
}
