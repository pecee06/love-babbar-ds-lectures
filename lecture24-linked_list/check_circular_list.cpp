#include <iostream>
#include "singly_linked_list.cpp"
#include "circular_linked_list.cpp"
using namespace std;

bool isCircular(Node* head){
	Node* n = head;
	while (true){
		n = n->next;
		if (n == head) return true;
		else if (!n) return false;
	}
}

int main()
{
	List l1;
	CList l2;

	l1.addTail(12);
	l1.addTail(24);
	l1.addTail(2);

	l2.insert(12);
	l2.insert(24);
	l2.insert(2);

	cout<<isCircular(l1.getHead())<<endl;
	cout<<isCircular(l2.getHead());

	return 0;
}