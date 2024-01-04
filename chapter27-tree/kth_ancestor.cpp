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
    void ancestor(Node* r, int n, vector<int>& v){
        static bool found = false;
        if (r){
            if (!found) ancestor(r->lChild,n,v);
            if (!found) ancestor(r->rChild,n,v);
            
            if (r->key == n || found){
                found = true;
                if (r->key != n) v.push_back(r->key);
                return;
            }
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
    int ancestor(int n, int k){
        vector<int> parents;
        ancestor(root,n,parents);
        
        if (parents.size() >= k)
            return parents[k-1];
        return -1;
    }
};

int main()
{
    Tree t;
    t.buildTree();
    
    int n,k;
    cin>>n>>k;
    cout<<t.ancestor(n,k);
    
    return 0;
}
