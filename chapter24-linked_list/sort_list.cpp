// Problem: Given a linked list containing only 0s, 1s & 2s. Sort it
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
    void sort(){
        int freq[3] = {0};    // Since the list only contains 0s, 1s & 2s
        Node* n = head;
        while (n){
            if (n->key == 0) freq[0]++;
            else if (n->key == 1) freq[1]++;
            else freq[2]++;
            n = n->next;
        }
        n = head;
        int i=0;
        while (n){
            while (freq[i]>0){
                n->key = i;
                freq[i]--;
                n = n->next;
            }
            i++;
        }
    }
    void sort_2(){
        List* temp1 = new List;
        List* temp2 = new List;
        List* temp3 = new List;
        Node* n = head;
        while (n){
            if (n->key == 0) temp1->insert(n->key);
            else if (n->key == 1) temp2->insert(n->key);
            else temp3->insert(n->key);
            n = n->next;
        }
        temp1->tail()->next = temp2->head;
        temp2->tail()->next = temp3->head;
        n = head;
        while (n){
            Node* popped = n;
            n = n->next;
            delete popped;
        }
        head = temp1->head;
    }
    void print(){
        print(head);
        cout<<endl;
    }
};

int main()
{
    List l;
    l.insert(1);
    l.insert(0);
    l.insert(0);
    l.insert(2);
    l.insert(1);
    l.insert(2);
    l.insert(0);
    l.insert(2);
    l.insert(1);

    cout<<"Before sorting\n";
    l.print();
    cout<<"After sorting\n";
    l.sort();
    l.print();
    
    return 0;
}
