#include <iostream>
#include <vector>
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
    Node* lca(Node* r, Node*& n1, Node*& n2){
        if (r){
            if (r->key == n1->key || r->key == n2->key) return r;
            
            Node* leftAns = lca(r->lChild,n1,n2);
            Node* rightAns = lca(r->rChild,n1,n2);

            if (leftAns && rightAns) return r;
            if (leftAns && !rightAns) return leftAns;
            if (!leftAns && rightAns) return rightAns;
            return NULL;
        }
        return NULL;
    }
    void find(Node* r, int key, Node*& n){
        if (r){
            if (key == r->key){
                n = r;
                return;
            }
            find(r->lChild,key,n);
            find(r->rChild,key,n);
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
    int lca(int k1, int k2){
        Node *n1 = NULL,*n2 = NULL;
        find(root,k1,n1);
        find(root,k2,n2);

        Node* commonAncestor = lca(root,n1,n2);
        if (commonAncestor) return commonAncestor->key;
        return -1;
    }
};

int main()
{
    Tree t;
    t.buildTree();

    cout<<"Enter keys to find common ancestor\n";
    int k1,k2;
    cin>>k1>>k2;

    cout<<"Common ancestor = "<<t.lca(k1,k2)<<endl;
    
    return 0;
}
