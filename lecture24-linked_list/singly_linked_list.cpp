#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
};

class List{
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
    List(){
        headPtr = new Node;
        headPtr->next = NULL;
        tail = headPtr;
    }

    Node* getHeadPtr(){
        return headPtr;
    }
    Node* getHead(){
        return headPtr->next;
    }
    void addHead(int data){
        Node* n = new Node;
        n->data = data;
        if (this->empty()) tail = n;
        n->next = headPtr->next;
        headPtr->next = n;
    }
    void addTail(int data){
        Node* n = new Node;
        n->data = data;
        tail->next = n;
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
        temp->next = n;
        if (temp == tail) tail = n;
    }
    void delHead(){
        Node* n = headPtr->next;
        headPtr->next = n->next;
        free(n);
    }
    void delTail(){
        Node* n = headPtr;
        while (n->next != tail){
            n = n->next;
        }
        Node* toBeDeleted = tail;
        n->next = NULL;
        tail = n;
        free(toBeDeleted);
    }
    void remove(int elem){
        if (!this->empty()){
            Node* n = headPtr;
            bool found = false;
            while (n->next != NULL){
                if (n->next->data == elem){
                    found = true;
                    break;
                }
                n = n->next;
            }
            if (found){
                Node* toBeDeleted = n->next;
                n->next = toBeDeleted->next;
                if (toBeDeleted == tail) tail = n;
                delete toBeDeleted;
            }
            else cout<<"Element not present in list\n";
        }
        else cout<<"List is empty\n";
    }
    void print(){
        Node* n = headPtr->next;
        while (n != NULL){
            cout<<n->data<<" ";
            n = n->next;
        }
        cout<<endl;
    }

    ~List(){
        del(headPtr);
    }
};
/*
int main()
{
    List l;
    
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
*/