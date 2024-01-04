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

            cout<<"Enter right child of "<<n->key<<": ";
            cin>>key;
            n->rChild = (key != -1)?createNode(key):NULL;

            buildTree(n->lChild);
            buildTree(n->rChild);
        }
    }
    void preOrderTraversal(Node* n){
        if (n){
            cout<<n->key<<" ";
            preOrderTraversal(n->lChild);
            preOrderTraversal(n->rChild);
        }
    }
    void inOrderTraversal(Node* n){
        if (n){
            inOrderTraversal(n->lChild);
            cout<<n->key<<" ";
            inOrderTraversal(n->rChild);
        }
    }
    void postOrderTraversal(Node* n){
        if (n){
            postOrderTraversal(n->lChild);
            postOrderTraversal(n->rChild);
            cout<<n->key<<" ";
        }
    }
    void countLeafs(Node* n, int& count){
        if (n){
            if (!(n->lChild) && !(n->rChild)) count++;
            countLeafs(n->lChild,count);
            countLeafs(n->rChild,count);
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
    void buildInLevelOrder(){
        cout<<"Enter root : ";
        int key;
        cin>>key;
        root = createNode(key);

        queue<Node*> q;
        q.push(root);
        while (!q.empty()){
            Node* n = q.front();
            q.pop();

            cout<<"Enter left child of "<<n->key<<": ";
            int key;
            cin>>key;
            n->lChild = (key != -1)?createNode(key):NULL;
            if (n->lChild) q.push(n->lChild);

            cout<<"Enter right child of "<<n->key<<": ";
            cin>>key;
            n->rChild = (key != -1)?createNode(key):NULL;
            if (n->rChild) q.push(n->rChild);
        }
    }
    void levelOrderTraversal(){
        if (!root) return;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()){
            Node* n = q.front();
            cout<<n->key<<" ";
            q.pop();
            if (n->lChild) q.push(n->lChild);
            if (n->rChild) q.push(n->rChild);
        }
    }
    void preOrderTraversal(){
        preOrderTraversal(root);
        cout<<endl;
    }
    void inOrderTraversal(){
        inOrderTraversal(root);
        cout<<endl;
    }
    void postOrderTraversal(){
        postOrderTraversal(root);
        cout<<endl;
    }
    int leafs(){
        int count = 0;
        countLeafs(root,count);
        return count;
    }
};

int main()
{
    Tree t;
    // t.buildTree();
    t.buildInLevelOrder();
    // t.levelOrderTraversal();
    // t.postOrderTraversal();
    cout<<"No. of leaf nodes = "<<t.leafs()<<endl;

    return 0;
}