#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Node{
public:
	int data;
	Node* leftChild;
	Node* rightChild;
};

class Tree{
	Node* rootPtr;
	void inputRoot(int data){
		Node* root = new Node;
		root->data = data;
		rootPtr->leftChild = root;
		rootPtr->rightChild = root;
	}
public:
	Tree(){
		rootPtr = new Node;
		rootPtr->leftChild = NULL;
		rootPtr->rightChild = NULL;
	}
	Node* getRoot(){
		return rootPtr->leftChild;
	}
	void input(){
		cout<<"Enter the value of root : ";
		int temp;
		cin>>temp;
		inputRoot(temp);
		queue<Node*> q;
		q.push(getRoot());
		while (!q.empty()){
			Node* ptr = q.front();
			q.pop();
			cout<<"Left child of "<<ptr->data<<" : ";
			cin>>temp;
			if (temp>=0){
				Node* child = new Node;
				child->data = temp;
				ptr->leftChild = child;
				child->leftChild = NULL;
				child->rightChild = NULL;
				q.push(child);
			}
			cout<<"Right child of "<<ptr->data<<" : ";
			cin>>temp;
			if (temp>=0){
				Node* child = new Node;
				child->data = temp;
				ptr->rightChild = child;
				child->leftChild = NULL;
				child->rightChild = NULL;
				q.push(child);
			}
		}
	}
	void preorderTraversal(){
		stack<Node*> s;
		Node* n = rootPtr->leftChild;
		while(n || !s.empty()){
			if (n){
				cout<<n->data<<" ";
				s.push(n);
				n = n->leftChild;
			}
			else{
				n = s.top();
				s.pop();
				n = n->rightChild;
			}
		}
		cout<<endl;
	}
	void inorderTraversal(){
		stack<Node*> s;
		Node* n = rootPtr->leftChild;
		while(n || !s.empty()){
			if (n){
				s.push(n);
				n = n->leftChild;
			}
			else{
				n = s.top();
				cout<<n->data<<" ";
				s.pop();
				n = n->rightChild;
			}
		}
		cout<<endl;
	}
	void levelorderTraversal(){
		queue<Node*> q;
		Node* n = rootPtr->leftChild;
		q.push(n);
		while (!q.empty()){
			n = q.front();
			q.pop();
			if (n) cout<<n->data<<" ";
			if (n->leftChild) q.push(n->leftChild);
			if (n->rightChild) q.push(n->rightChild);
		}
		cout<<endl;
	}
};

int main()
{
	Tree t;
	t.input();
	// t.preorderTraversal();
	// t.inorderTraversal();
	t.levelorderTraversal();

	return 0;
}