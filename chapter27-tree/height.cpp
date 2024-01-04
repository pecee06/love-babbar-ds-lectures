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
    int height(Node* n){
        if (n){
            int x = height(n->lChild);
            int y = height(n->rChild);
            return (x>y)?x+1:y+1;
        }
        return -1;
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
    int height(){
        return height(root);
    }
};

int main()
{
    Tree t;
    t.buildTree();
    cout<<"Height = "<<t.height()<<endl;
    
    return 0;
}
