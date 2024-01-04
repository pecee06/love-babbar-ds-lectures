#include <iostream>
#include <stack>
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
    void reverse_2(Node* curr, Node* prev){
        if (curr == NULL){
            headPtr->next = prev;
            return;
        }
        reverse_2(curr->next,curr);
        curr->next = prev;
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

    void addNode(int data){
        Node* n = new Node;
        n->data = data;
        tail->next = n;
        n->next = NULL;
        tail = n;
    }
    void reverse_1(){
        Node *prev = NULL, *curr = headPtr->next, *forward;
        while (curr != NULL){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        tail = headPtr->next;
        headPtr->next = prev;
    }
    void reverse_2(){
        tail = headPtr->next;
        reverse_2(tail, NULL);
    }
    void reverse_3(){
        stack<int> s;
        Node* n = headPtr->next;
        while (n!=NULL){
            s.push(n->data);
            n = n->next;
        }
        n = headPtr->next;
        while (n!=NULL){
            n->data = s.top();
            s.pop();
            n = n->next;
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

    ~List(){
        del(headPtr);
    }
};

int main()
{
    List l;
    
    int n;
    cout<<"How many elements you want to enter : ";
    cin>>n;

    int temp;
    for (register int i=0; i<n; i++){
        cin>>temp;
        l.addNode(temp);
    }

    // l.reverse_1();
    // l.reverse_2();
    l.reverse_3();
    cout<<"After reversing the list\n";
    l.print();

    return 0;
}