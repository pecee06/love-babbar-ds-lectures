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

            buildTree(n->lChild);

            cout<<"Enter right child of "<<n->key<<": ";
            cin>>key;
            n->rChild = (key != -1)?createNode(key):NULL;
            
            buildTree(n->rChild);
        }
    }

    void ksumPaths(Node* n, int k, deque<int>& q, int& paths){
        if (n){
            q.push_front(n->key);
            ksumPaths(n->lChild,k,q,paths);
            ksumPaths(n->rChild,k,q,paths);

            int sum = 0;
            for (auto it = q.begin(); it != q.end(); it++){
                sum += *it;
                if (sum == k){
                    paths++;
                    return;
                }

                if (sum > k) return;
            }

            q.pop_front();
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

    int ksumPaths(int k){
        deque<int> q;
        int paths = 0;
        ksumPaths(root,k,q,paths);
        return paths;
    }
};

int main()
{
    Tree t;
    t.buildTree();

    cout<<"Enter value of k : ";
    int n;
    cin>>n;
    cout<<t.ksumPaths(n);
    
    return 0;
}
