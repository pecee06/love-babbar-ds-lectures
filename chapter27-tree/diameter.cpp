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
    pair<int,int> diameterHelper(Node* n){
        // first-> diameter
        // second-> height

        if (n){
            pair<int,int> left = diameterHelper(n->lChild);
            pair<int,int> right = diameterHelper(n->rChild);

            // 3 cases
            int option1 = left.first;   // diameter can be found in the left subtree
            int option2 = right.first;  // diameter can be found in the right subtree
            int option3 = left.second + right.second + 1;   // we have to consider both subtrees

            pair<int,int> ans;
            ans.first = max(option1,max(option2,option3));  // for height
            ans.second = max(left.second,right.second) + 1; // for diameter
            return ans;
        }
        pair<int,int> p = make_pair(0,-1);
        return p;
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
    int diameter(){
        return diameterHelper(root).first;
    }
};

int main()
{
    Tree t;
    t.buildTree();
    cout<<"Diameter = "<<t.diameter()<<endl;
    
    return 0;
}
