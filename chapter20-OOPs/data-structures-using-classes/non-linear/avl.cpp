#include <iostream>
using namespace std;

class AVL{
    typedef struct Node
    {
        int key, height;
        struct Node *lChild, *rChild;
    } node;
    node* root;

    node* createNode(int key){
        node* n = new node;
        n->key = key;
        n->lChild = n->rChild = NULL;
        n->height = 0;
        return n;
    }
    int max(int a, int b){
        return (a>b)?a:b;
    }
    void evalHeight(node* n){
        if (n->lChild && n->rChild)
            n->height = max(n->lChild->height,n->rChild->height)+1;
        else if (n->lChild)
            n->height = n->lChild->height+1;
        else if (n->rChild)
            n->height = n->rChild->height+1;
    }
    void insert(node* prev, node* curr, int key){
        if (!curr){
            node* child = createNode(key);
            if (key < prev->key) prev->lChild = child;
            else prev->rChild = child;
            return;
        }
        
        if (key < curr->key) insert(curr,curr->lChild,key);
        else if (key > curr->key) insert(curr,curr->rChild,key);
        else return;
        
        evalHeight(curr);
    }
    bool isLeaf(node* n){
        return !n->lChild && !n->rChild;
    }
    node* inPre(node* n){
        node* temp = n;
        temp = temp->lChild;
        while (temp && temp->rChild)
            temp = temp->rChild;
        return temp;
    }
    node* inSucc(node* n){
        node* temp = n;
        temp = temp->rChild;
        while (temp && temp->lChild)
            temp = temp->lChild;
        return temp;
    }
    void remove(node* prev, node* curr, int key){
        if (!curr) return;
        if (key < curr->key)
            remove(curr,curr->lChild,key);
        else if (key > curr->key)
            remove(curr,curr->rChild,key);
        else{
            if (isLeaf(curr)){
                if (prev && prev->lChild == curr)
                    prev->lChild = NULL;
                else if (prev && prev->rChild == curr)
                    prev->rChild = NULL;
                delete curr;
                return;
            }
            else{
                node* predessesor = inPre(curr);
                node* successor = inSucc(curr);
                if (predessesor) prev = predessesor;
                else prev = successor;
                curr->key = prev->key;
                if (predessesor)
                    remove(curr,curr->lChild,curr->key);
                else remove(curr,curr->rChild,curr->key);
            }
        }
    }
    void inorder(node* n){
        if (!n) return;
        inorder(n->lChild);
        cout<<n->key<<" ";
        inorder(n->rChild);
    }
public:
    AVL(){
        root = NULL;
    }
    void insert(int key){
        if (root)
            insert(NULL,root,key);
        else root = createNode(key);
    }
    void remove(int key){
        remove(NULL,root,key);
    }
    void inorder(){
        inorder(root);
        cout<<endl;
    }
    int height(){
        return root->height;
    }
};

int main()
{
    cout<<"How many nodes : ";
    int n;
    cin>>n;

    AVL t;
    int temp;
    cout<<"Enter nodes\n";
    for (register int i=0; i<n; i++){
        cin>>temp;
        t.insert(temp);
    }

    cout<<t.height();

    return 0;
}