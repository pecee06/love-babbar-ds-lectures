#include <iostream>
#include <queue>
using namespace std;

class Tree{
    class Node{
    public:
        int key;
        Node *lChild, *rChild;
    };
    Node* root;

    Node* createNode(int key){
        Node* n = new Node;
        n->key = key;
        n->lChild = n->rChild = NULL;
        return n;
    }
    void buildTree(Node* n){
        if (n){
            cout<<"Enter left child of "<<n->key<<": ";
            int key;
            cin>>key;
            n->lChild = (key != -1)?createNode(key):NULL;

            buildTree(n->lChild);

            cout<<"Enter right child of "<<n->key<<": ";
            cin>>key;
            n->rChild = (key != -1)?createNode(key):NULL;
            
            buildTree(n->rChild);
        }
    }
    void printLeaves(Node* n){
        if (n){
            printLeaves(n->lChild);
            if ((!n->lChild) && (!n->rChild)) cout<<n->key<<" ";
            printLeaves(n->rChild);
        }
    }
    void printRightBoundary(Node* n){
        if (n){
            printRightBoundary(n->rChild);
            if ((n!=root) && (n->lChild || n->rChild)) cout<<n->key<<" ";
        }
    }
public:
    Tree():root(NULL){}

    void buildTree(){
        cout<<"Enter root : ";
        int key;
        cin>>key;
        root = createNode(key);
        buildTree(root);
    }
    void boundaryTraversal(){
        // Left side
        Node* n = root;
        while (n->lChild){
            cout<<n->key<<" ";
            n = n->lChild;
        }
        // Leaves
        this->printLeaves(root);
        // Right side
        this->printRightBoundary(root);
    }
};

int main()
{
    Tree t;
    t.buildTree();
    t.boundaryTraversal();
    
    return 0;
}
