// Problem: 2 numbers are represented using a linked-list, add them and output the resultant linked-list

#include <iostream>
using namespace std;

class Number{
    class Node{
    public:
        int key;
        Node* next;
    };

    Node* createNode(int key){
        Node* n = new Node;
        n->key = key;
        n->next = NULL;
        return n;
    }
    Node* tail(){
        Node* n = head;
        while (n->next) n = n->next;
        return n;
    }
    void print(Node* n){
        if (n){
            cout<<n->key<<" ";
            print(n->next);
        }
    }
public:
    Node* head;
    Number():head(NULL){}

    void insert(int key){
        if (head){
            Node* n = head;
            while (n->next) n = n->next;
            n->next = createNode(key);
        }
        else head = createNode(key);
    }
    void reverse(){
        Node *left = NULL, *curr = NULL, *right = head;
        while (right){
            left = curr;
            curr = right;
            right = right->next;
            curr->next = left;
        }
        head = curr;
    }
    Number operator+(Number& l){
        Number obj;
        int a = 0, b = 0;
        Node *n1 = head, *n2 = l.head;
        while (n1){
            a *= 10;
            a += n1->key;
            n1 = n1->next;
        }
        while (n2){
            b *= 10;
            b += n2->key;
            n2 = n2->next;
        }
        int c = a+b;
        Number n;
        while (c){
            n.insert(c%10);
            c /= 10;
        }
        n.reverse();
        return n;
    }
    void print(){
        print(head);
        cout<<endl;
    }
};

int main()
{
    Number n1, n2;

    n1.insert(4);
    n1.insert(5);

    n2.insert(3);
    n2.insert(4);
    n2.insert(5);

    Number n3 = n1+n2;
    n3.print();
    
    return 0;
}
