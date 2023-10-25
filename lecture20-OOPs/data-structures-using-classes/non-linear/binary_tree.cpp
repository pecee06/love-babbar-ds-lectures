#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* leftChild;
    Node* rightChild;
};

class BinaryTree{
    Node* root;

    void input(Node* n){
        cout<<"Want to enter to the left of "<<n->data<<" (0/1): ";
        bool left;
        cin>>left;
        int temp;
        if (left){
            cout<<"Enter value : ";
            cin>>temp;
            Node* leftNode = new Node;
            n->leftChild = leftNode;
            leftNode->data = temp;
            leftNode->leftChild = NULL;
            leftNode->rightChild = NULL;
            input(leftNode);
        }

        cout<<"Want to enter to the right of "<<n->data<<" (0/1): ";
        bool right;
        cin>>right;
        if (right){
            cout<<"Enter value : ";
            cin>>temp;
            Node* rightNode = new Node;
            n->rightChild = rightNode;
            rightNode->data = temp;
            rightNode->leftChild = NULL;
            rightNode->rightChild = NULL;
            input(rightNode);
        }
    }
    void preorder(Node* n){
        if (n == NULL){
            return;
        }
        cout<<n->data<<" ";
        preorder(n->leftChild);
        preorder(n->rightChild);
    }
    bool isBST(Node* n){
        if (n == NULL){
            return true;
        }
        if (! isBST(n->leftChild)){
            return false;
        }
        static Node* prev = NULL;
        if (prev != NULL && n->data <= prev->data){
            return false;
        }
        prev = n;
        return isBST(n->rightChild);
    }
public:
    BinaryTree(){
        root = new Node;
        root->leftChild = NULL;
        root->rightChild = NULL;
    }

    void input(){
        cout<<"Enter root : ";
        int temp;
        cin>>temp;
        root->data = temp;
        this->input(root);
    }
    void isBST(){
        if (isBST(root)){
            cout<<"Given tree is BST\n";
        }
        else{
            cout<<"Given tree isn't a BST\n";
        }
    }
    void preorder(){
        this->preorder(root);
        cout<<endl;
    }
};

int main()
{
    BinaryTree t;
    t.input();
    t.isBST();
    t.preorder();
    
    return 0;
}
