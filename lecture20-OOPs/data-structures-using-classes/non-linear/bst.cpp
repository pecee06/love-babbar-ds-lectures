#include <iostream>
#include <cmath>
using namespace std;

class BST{
    class Node{
    public:
        int data;
        Node* leftChild;
        Node* rightChild;
        int height;
    };
    Node* root;

    void inorder(Node* n){
        if (n == NULL){
            return;
        }
        inorder(n->leftChild);
        cout<<n->data<<" ";
        inorder(n->rightChild);
    }
    Node* insert(Node* n, int data){
        if (n == NULL){
            Node* node = new Node;
            node->data = data;
            node->leftChild = NULL;
            node->rightChild = NULL;
            return node;
        }
        
        if (data < n->data){
            n->leftChild = insert(n->leftChild,data);
        }
        if (data > n->data){
            n->rightChild = insert(n->rightChild,data);
        }

        return n;
    }
    Node* present(Node* n, int data){
        if (n == NULL){
            return NULL;
        }
        if (data < n->data){
            present(n->leftChild,data);
        }
        else if (data > n->data){
            present(n->rightChild,data);
        }
        else{
            return n;
        }
    }
public:
    BST(int data){
        root = new Node;
        root->data = data;
        root->leftChild = NULL;
        root->rightChild = NULL;
        root->height = 0;
    }

    void insert(int data){
        this->insert(root,data);
    }

    void present(int data){
        if(this->present(root,data) != NULL){
            cout<<data<<" is present in the BST\n";
        }
        else{
            cout<<data<<" isn't present in the BST\n";
        }
    }
    
    void inorder(){
        this->inorder(root);
        cout<<endl;
    }
};

int main()
{
    BST t(10);
    t.insert(7);
    t.insert(4);
    t.insert(5);
    t.insert(9);

    t.present(5);
    t.present(9);
    t.present(10);
    t.present(45);

    t.inorder();
    
    return 0;
}
