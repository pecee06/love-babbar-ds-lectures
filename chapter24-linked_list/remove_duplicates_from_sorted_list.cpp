#include <iostream>
#include "singly_linked_list.cpp"
using namespace std;

void removeDuplicates(Node* head){
	Node *prev = NULL, *curr = head;
	while (curr!=NULL){
		Node* toBeDeleted = NULL;
        if (prev && curr->data == prev->data) {
            prev->next = curr->next;
            toBeDeleted = curr;
        }
        else prev = curr;
        curr = curr->next;
        delete toBeDeleted;
	}
}

int main()
{
	List l;

	l.addTail(26);
	l.addTail(26);
	l.addTail(13);
	l.addTail(13);
	l.addTail(13);
	l.addTail(13);
	l.addTail(11);
	l.addTail(11);
	l.print();

	printf("After removing duplicates\n");
	removeDuplicates(l.getHead());
	l.print();

	return 0;
}