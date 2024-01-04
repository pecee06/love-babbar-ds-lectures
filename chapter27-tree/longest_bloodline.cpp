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
    void bloodline(Node* n, pair<int,int> temp, pair<int,int>& ans){
        if (n){
            temp.first++;
            temp.second += n->key;
            bloodline(n->lChild,temp,ans);
            bloodline(n->rChild,temp,ans);
        }
        else{
            if (temp.first > ans.first) ans = temp;
            else if ((temp.first == ans.first) && (temp.second > ans.second))
                ans = temp;
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
    int bloodline(){
        // path-length, sum
        pair<int,int> temp,ans;

        temp = ans = make_pair(0,0);
        bloodline(root,temp,ans);
        return ans.second;
    }
};

int main()
{
    Tree t;
    t.buildTree();
    cout<<"Sum of nodes in longest path = "<<t.bloodline()<<endl;
    
    return 0;
}
