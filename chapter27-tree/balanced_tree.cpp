#include <iostream>
using namespace std;

class Tree{
    class Node{
    public:
        int key, height;
        Node *lChild, *rChild;
    };
    Node* root;

    Node* createNode(int key){
        Node* n = new Node;
        n->key = key;
        n->height = 0;
        n->lChild = n->rChild = NULL;
        return n;
    }
    void buildTree(Node* n){
        if (n){
            cout<<"Enter left child of "<<n->key<<": ";
            int key;
            cin>>key;
            n->lChild = (key != -1)?createNode(key):NULL;

            cout<<"Enter right child of "<<n->key<<": ";
            cin>>key;
            n->rChild = (key != -1)?createNode(key):NULL;

            int l = (n->lChild)?n->lChild->height:-1;
            int r = (n->rChild)?n->rChild->height:-1;

            n->height = max(l,r)+1;
            
            buildTree(n->lChild);
            buildTree(n->rChild);
        }
    }
    bool balanced(Node* n){
        if (n){
            int l = (n->lChild)?n->lChild->height:-1;
            int r = (n->rChild)?n->rChild->height:-1;
            int bf = l-r;
            
            if (bf >= -1 && bf <= 1)
                return balanced(n->lChild) && balanced(n->rChild);
            return false;
        }
        return true;
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
    bool balanced(){
        return balanced(root);
    }
};

int main()
{
    Tree t;
    t.buildTree();

    if (t.balanced())
        cout<<"Tree is height balanced\n";
    else cout<<"Tree ain't height balanced\n";
    
    return 0;
}
