#include <iostream>
using namespace std;

class List{
    class Node{
    public:
        int key;
        Node* next;
    };
    Node *head, *tail;

    Node* createNode(int key){
        Node* n = new Node;
        n->key = key;
        n->next = NULL;
        return n;
    }
    Node* middle(Node* n){
        Node *slow = n, *fast = n;
        while (fast && fast->next){
            slow = slow->next;
            fast = fast->next;
            if (fast) fast = fast->next;
        }
        return slow;
    }
    Node* merge(Node* h1, Node* h2){
        Node *h = NULL, *prev = NULL;
        if (h1->key <= h2->key) h = h1;
        else h = h2;

        // Conventionally inserting h2's elements into h1
        while (h2){
            if (h1 && h2->key >= h1->key && h1->next && h2->key <= h1->next->key){
                Node* temp = h2;
                h2 = h2->next;
                Node* n = n->next;
                h1->next = temp;
                temp->next = n;
            }
        }

        return h;
    }
    Node* sort(Node* n){
        if (!n || !n->next) return n;
        Node* m = middle(n);
        Node* l = n;
        Node* r = m->next;
        m->next = NULL;

        l = sort(l);
        r = sort(r);

        return merge(l,r);
    }
public:
    List(){
        head = tail = NULL;
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
    void sort(){
        sort(head);
    }
    void print(){
        Node* n = head;
        while (n){
            cout<<n->key<<" ";
        }
        cout<<endl;
    }
};

int main()
{
    List l;
    l.insert(3);
    l.insert(5);
    l.insert(1);
    l.insert(2);
    l.insert(9);
    l.sort();
    l.print();

    return 0;
}