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
    void leftView(Node* n, int level){
        static int size = 0;
        if (n){
            if (level == size){
                cout<<n->key<<" ";
                size++;
            }
            leftView(n->lChild,level+1);
            leftView(n->rChild,level+1);
        }
    }
    void rightView(Node* n, int level){
        static int size = 0;
        if (n){
            if (level == size){
                cout<<n->key<<" ";
                size++;
            }
            rightView(n->rChild,level+1);
            rightView(n->lChild,level+1);
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
    void leftView(){
        leftView(root,0);
    }
    void rightView(){
        rightView(root,0);
    }
};

int main()
{
    Tree t;
    t.buildTree();
    // t.leftView();
    t.rightView();
    
    return 0;
}
