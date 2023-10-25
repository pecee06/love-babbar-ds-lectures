#include <iostream>
#include <climits>
#include <queue>
using namespace std;

class Node{
public:
	int data;
	Node* next;
};

bool hasLoop(Node* head){
	queue<int> q;
	Node* n = head;
	bool loop = false;
	while (n){
	    q.push(n->data);
		n->data = INT_MIN;
		if (n->next && n->next->data == INT_MIN){
			loop = true;
			break;
		}
		n = n->next;
	}

	n = head;
	while (!q.empty()){
		n->data = q.front();
		q.pop();
		n = n->next;
	}

	return loop;
}

Node* floydCycle(Node* head){
	Node *slow, *fast;
	slow = fast = head;
	while (fast && fast->next){
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast){
			return slow;
		}
	}
	return NULL;
}

void removeLoop(Node* head){
	Node* startingNode = floydCycle(head);
	Node* n = head;
	while (n->next!=startingNode){
		n = n->next;
	}
	n->next = NULL;
}

void print(Node* head){
	if (head == NULL) return;
	cout<<head->data<<" ";
	print(head->next);
}

int main()
{
	Node* head = new Node;
	Node* m1 = new Node;
	Node* m2 = new Node;
	Node* m3 = new Node;
	Node* m4 = new Node;

	Node* nodes[] = {head,m1,m2,m3,m4};

	head->data = 1;
	m1->data = 2;
	m2->data = 3;
	m3->data = 4;
	m4->data = 5;
	
	head->next = m1;
	m1->next = m2;
	m2->next = m3;
	m3->next = m4;
	// m4->next = m1;
	m4->next = head;

	// if (hasLoop(head)) cout<<"Loop is present\n";
	// else cout<<"Loop ain't present\n";

	// Node* n = floydCycle(head);
	// if (n) cout<<"Starting node of loop : "<<n->data<<endl;
	// else cout<<"No loop exists\n";

	removeLoop(head);
	print(head);

	int n = sizeof(nodes)/sizeof(nodes[0]);
	for (register int i=0; i<n; i++)
		delete nodes[i];

	return 0;
}