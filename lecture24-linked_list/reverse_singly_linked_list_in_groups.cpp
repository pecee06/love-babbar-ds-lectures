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
    void revIn_1_helper(Node* from, int k){
        if (from==NULL){
            return;
        }
        stack<int> s;
        Node* n = from;
        for (register int i=0; i<k; i++){
            s.push(n->data);
            n = n->next;
            if (n==NULL) break;
        }
        while (!s.empty()){
            from->data = s.top();
            s.pop();
            from = from->next;
        }
        revIn_1_helper(from,k);
    }
    Node* revIn_2_helper(Node* prev, Node* curr, int k){
        // code
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
    void revIn_1(int k){
        revIn_1_helper(headPtr->next,k);
    }
    void revIn_2(int k){
        revIn_2_helper(NULL, headPtr->next, k);
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

    int k;
    cout<<"In groups of how many nodes, you want to reverse the list : ";
    cin>>k;

    // l.revIn_1(k);
    l.revIn_2(k);
    cout<<"After reversing the list\n";
    l.print();

    return 0;
}