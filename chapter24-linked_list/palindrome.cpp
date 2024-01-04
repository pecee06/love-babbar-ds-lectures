// Problem: Check if a given list, a palindrome or not

#include <iostream>
using namespace std;

class List{
    class Node{
    public:
        int key;
        Node* next;
    };
    Node* head;

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
    Node* middle(){
        Node *slow = head, *fast = head;
        while (fast && fast->next){
            slow = slow->next;
            fast = fast->next;
            if (fast) fast = fast->next;
        }
        return slow;
    }
    Node* prev(Node* n){
        Node* temp = head;
        while (temp){
            if (temp->next == n) return temp;
            temp = temp->next;
        }
    }
    void reverse(Node* prev, Node* curr){
        Node *left = NULL, *leftmost = NULL;
        while (curr){
            leftmost = left;
            left = curr;
            curr = curr->next;
            left->next = leftmost;
        }
        prev->next = left;
    }
public:
    List():head(NULL){}

    void insert(int key){
        if (head){
            Node* n = head;
            while (n->next) n = n->next;
            n->next = createNode(key);
        }
        else head = createNode(key);
    }
    bool palindrome(){
        Node* mid = middle();
        reverse(prev(mid),mid);
        Node* left = head;
        while (mid->next){
            if (left->key != mid->key) return false;
            left = left->next;
            mid = mid->next;
        }
        return true;
    }
};

int main()
{
    List l;
    
    int n;
    cin>>n;
    for (int i=0; i<n; i++){
        int temp;
        cin>>temp;
        l.insert(temp);
    }

    if (l.palindrome()) cout<<"List is palindrome\n";
    else cout<<"List isn't palindrome\n";
    
    return 0;
}
