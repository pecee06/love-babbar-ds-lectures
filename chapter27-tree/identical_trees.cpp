#include <iostream>
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
    bool areEqual(Node* r1, Node* r2){
        if (r1 && r2){
            if (r1->key == r2->key)
                return areEqual(r1->lChild,r2->lChild) && areEqual(r1->rChild,r2->rChild);
            return false;
        }
        if (r1) return false;
        if (r2) return false;
        return true;
    }
public:
    Tree():root(NULL){}

    Node* getRoot(){
        return root;
    }
    void buildTree(){
        cout<<"Enter root : ";
        int key;
        cin>>key;
        root = createNode(key);
        buildTree(root);
    }
    
    bool operator==(Tree& t){
        return areEqual(root,t.getRoot());
    }
};

int main()
{
    Tree t1, t2;

    cout<<"First Tree\n";
    t1.buildTree();

    cout<<"Second Tree\n";
    t2.buildTree();

    if (t1 == t2)
        cout<<"Trees are identical\n";
    else cout<<"Trees aren't identical\n";
    
    return 0;
}
