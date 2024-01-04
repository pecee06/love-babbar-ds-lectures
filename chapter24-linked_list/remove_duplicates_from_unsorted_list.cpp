#include <iostream>
#include "singly_linked_list.cpp"
#include <unordered_map>
using namespace std;

void removeDuplicates(Node* head){
	unordered_map<int,Node*> m;
	Node *prev = NULL, *curr = head;
	while(curr!=NULL){
		Node* toBeDeleted = NULL;
		if (!m.empty() && m[curr->data] != NULL){
			prev->next = curr->next;
			toBeDeleted = curr;
		}
		else{
			m[curr->data] = curr;
			prev = curr;
		}
		curr = curr->next;
		delete toBeDeleted;
	}
}

int main()
{
	List l;

	l.addTail(4);
	l.addTail(2);
	l.addTail(5);
	l.addTail(4);
	l.addTail(2);
	l.addTail(2);
	l.print();

	printf("After removing duplicates\n");
	removeDuplicates(l.getHead());
	l.print();

	return 0;
}