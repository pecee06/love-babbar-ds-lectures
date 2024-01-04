// Problem: Clone a linked-list having random pointers

#include <iostream>
using namespace std;

class List{
    class Node{
    public:
        int key;
        Node *next, *rand;
    };
    Node *head, *tail;

    Node* createNode(int key){
        Node* n = new Node;
        n->key = key;
        n->next = n->rand = NULL;
        return n;
    }
    Node* nodeOf(int key){
        Node* n = head;
        while (n){
            if (key == n->key) return n;
            n = n->next;
        }
        return NULL;
    }
public:
    List(){
        head = tail = NULL;
    }
    List(List& l){
        head = tail = NULL;
        // Cloning
        Node* n = l.getHead();
        while (n){
            this->insert(n->key);
            n = n->next;
        }
        // Creating zig-zag links
        n = head;
        Node* left = l.getHead();
        Node* right = left->next;
        while (n){
            n = insert(n,left,right);
            left = right;
            if (right) right = right->next;
        }
        // Establishing random links
        n = l.getHead();
        while (n){
            if (n->rand) n->next->rand = n->rand->next;
            else n->next->rand = NULL;
            n = n->next->next;
        }
        // Re-establishing OG links
        Node* linear1 = l.getHead();
        Node *linear2 = linear1->next, *zigZag = linear1;
        while (zigZag){
            zigZag = zigZag->next;
            linear1->next = zigZag->next;
            linear1 = zigZag->next;
            zigZag = zigZag->next;
            if (zigZag && zigZag->next){
                linear2->next = zigZag->next;
                linear2 = zigZag->next;
            }
            else linear2->next = NULL;
        }
    }

    Node* getHead(){
        return head;
    }
    Node* insert(Node* n, Node* left, Node* right){
        Node* m = n->next;
        left->next = n;
        n->next = right;
        return m;
    }
    void insert(int key){
        if (head){
            Node* n = createNode(key);
            tail->next = n;
            tail = n;
        }
        else{
            head = createNode(key);
            tail = head;
        }
    }
    void createLink(int from, int to){
        Node* n1 = nodeOf(from);
        Node* n2 = nodeOf(to);
        if (n1 && n2) n1->rand = n2;
    }
    void print(){
        Node* n = head;
        while (n){
            cout<<n->key<<" ";
            if (n->rand) cout<<"linked to "<<n->rand->key;
            cout<<endl;
            n = n->next;
        }
    }

    ~List(){
        Node* n = head;
        while (n){
            Node* popped = n;
            n = n->next;
            delete popped;
        }
    }
};

int main()
{
    List* l = new List;
    l->insert(3);
    l->insert(5);
    l->insert(7);
    l->insert(10);
    l->insert(9);

    l->createLink(3,7);
    l->createLink(7,9);
    l->createLink(5,3);
    l->createLink(9,5);

    List clone(*l);
    cout<<"OG\n";
    l->print();
    delete l;
    cout<<"Clone\n";
    clone.print();
    
    return 0;
}
