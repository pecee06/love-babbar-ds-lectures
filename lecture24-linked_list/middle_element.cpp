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
    void del(Node* n){
        if (n == NULL){
            return;
        }
        del(n->next);
        delete n;
    }
    int size(){
        int nodes = 0;
        Node* n = headPtr->next;
        while (n!=NULL){
            nodes++;
            n = n->next;
        }
        return nodes;
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
    int middle_1(){
        int l = this->size();
        int middlePos = (l%2)?l/2+1:l/2;
        Node* n = headPtr->next;
        for (register int i=0; i<middlePos; i++){
            n = n->next;
        }
        return n->data;
    }
    int middle_2(){
        Node *fast, *slow;
        fast = slow = headPtr->next;
        while (fast){
            fast = fast->next;
            fast = (fast!=NULL)?fast->next:NULL;
            slow = slow->next;
        }
        return slow->data;
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
    for (register int i=1; i<n; i++){
        cin>>temp;
        l.addNode(temp);
    }
    
    // cout<<"Middle element to the list : "<<l.middle_1();
    cout<<"Middle element to the list : "<<l.middle_2();

    return 0;
}