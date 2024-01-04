#include <iostream>
#include <string>
using namespace std;

template<typename T> class Stack{
    class Node{
    public:
        T key;
        Node* next;
    };
    Node* top;

    Node* createNode(T key){
        Node* n = new Node;
        n->key = key;
        n->next = NULL;
        return n;
    }
public:
    Stack():top(NULL){}

    void push(T key){
        if (top){
            Node* n = createNode(key);
            n->next = top;
            top = n;
        }
        else top = createNode(key);
    }
    bool empty(){
        return !top;
    }
    void pop(){
        if (!this->empty()){
            Node* popped = top;
            top = top->next;
            delete popped;
        }
    }
    T peek(){
        if (top) return top->key;
        return (T)NULL;
    }

    ~Stack(){
        Node* n = top;
        while (n){
            Node* popped = n;
            n = n->next;
            delete popped;
        }
    }
};

int main()
{
    Stack<string> s;

    int n;
    cin>>n;
    string temp;
    for (int i=0; i<n; i++){
        cin>>temp;
        s.push(temp);
    }

    cout<<"Reverse Order\n";
    while (!s.empty()){
        cout<<s.peek()<<endl;
        s.pop();
    }

    return 0;
}