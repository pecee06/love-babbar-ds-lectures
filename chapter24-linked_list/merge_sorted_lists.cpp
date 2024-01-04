// Problem: Merge 2 sorted linked list
#include <iostream>
using namespace std;

class List{
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
    void print(Node* n){
        if (n){
            cout<<n->key<<" ";
            print(n->next);
        }
    }
    Node* tail(){
        Node* n = head;
        while (n->next) n = n->next;
        return n;
    }
    Node* insert(Node* n, int key){
        Node* nextNode = NULL;
        Node* newNode = createNode(key);
        if (!n) nextNode = head;
        else{
            nextNode = n->next;
            n->next = newNode;
        }
        if (nextNode) {
            newNode->next = nextNode;
        }
        return newNode;
    }
public:
    Node* head;
    List():head(NULL){}

    void insert(int key){
        if (head){
            Node* n = head;
            while (n->next) n = n->next;
            n->next = createNode(key);
        }
        else head = createNode(key);
    }
    void merge(List& obj){
        Node *prev = NULL, *curr = head, *ptr = obj.head;
        while (curr && ptr){
            if (curr->key < ptr->key){
                prev = curr;
                curr = curr->next;
            }
            else if (curr->key == ptr->key){
                insert(curr,ptr->key);
                prev = curr;
                curr = curr->next;
                ptr = ptr->next;
            }
            else{
                prev = insert(prev,ptr->key);
                ptr = ptr->next;
            }
        }
        while (ptr){
            insert(ptr->key);
            ptr = ptr->next;
        }
    }
    void print(){
        print(head);
        cout<<endl;
    }
};

int main()
{
    List l1, l2;
    
    l1.insert(1);
    l1.insert(1);
    l1.insert(2);
    l1.insert(4);

    l2.insert(0);
    l2.insert(2);
    l2.insert(3);
    l2.insert(10);
    l2.insert(13);
    l2.insert(13);

    l1.merge(l2);
    cout<<"Merged list\n";
    l1.print();

    return 0;
}
