#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
};

class CList{
    Node* startPtr;

    bool empty(){
        return startPtr->next == NULL;
    }
    void del(Node* n){
        if (n->next == startPtr->next){
            delete n;
            return;
        }
        del(n->next);
        delete n;
    }
    void print(Node* n){
        if (n == startPtr->next){
            return;
        }
        cout<<n->data<<" ";
        print(n->next);
    }
public:
    CList(){
        startPtr = new Node;
        startPtr->next = NULL;
    }

    Node* getHead(){
        return startPtr->next;
    }
    void insert(int data){
        Node* n = startPtr;
        if (!this->empty()){
            do{
                n = n->next;
            } while(n->next != startPtr->next);
        }
        Node* node = new Node;
        node->data = data;
        n->next = node;
        node->next = startPtr->next;
    }
    void remove(int elem){
        if (!this->empty()){
            bool found = false;
            Node* n = startPtr->next;
            while (n->next != startPtr->next){
                if (n->next->data == elem){
                    found = true;
                    break;
                }
                n = n->next;
            }
            if (n->next->data == elem){
                found = true;
                startPtr->next = n->next->next;
            }
            if (found){
                Node* toBeDeleted = n->next;
                n->next = toBeDeleted->next;
                delete toBeDeleted;
            }
            else cout<<"Element not present in list\n";
        }
        else cout<<"List is empty\n";
    }
    void print(){
        Node* n = startPtr->next;
        cout<<n->data<<" ";
        print(n->next);
        cout<<endl;
    }

    ~CList(){
        del(startPtr->next);
    }
};
/*
int main()
{
    CList l;

    l.insert(13);
    l.insert(7);
    l.insert(0);
    l.insert(-9);
    l.insert(11);
    l.insert(24);

    l.remove(64);
    l.remove(-9);
    l.remove(13);
    l.remove(24);

    l.print();
    
    return 0;
}
*/