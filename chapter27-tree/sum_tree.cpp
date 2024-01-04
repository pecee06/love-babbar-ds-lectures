// A sum tree is a binary tree in which every node has the key value equal to the sum of key values of its left subtree and its right subtree. An empty tree is also a sum tree. Check whether a given tree is sum tree or not

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
    pair<bool,int> sumTreeHelper(Node* n){
        if (!n) return make_pair(true,0);
        if (!(n->lChild) && !(n->rChild)) return make_pair(true,n->key);

        pair<bool,int> left = sumTreeHelper(n->lChild);
        pair<bool,int> right = sumTreeHelper(n->rChild);

        bool l = left.first;
        bool r = right.first;
        int sum = left.second + right.second;
        bool cond = n->key == sum;  // this may return false
        
        pair<bool,int> ans;
        ans.first = l&&r&&cond;
        if (ans.first) ans.second = 2*sum;

        return ans;
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
    bool sumTree(){
        return sumTreeHelper(root).first;
    }
};

int main()
{
    Tree t;
    t.buildTree();

    if (t.sumTree())
        cout<<"Is a sum tree\n";
    else cout<<"Isn't a sum tree\n";
    
    return 0;
}
