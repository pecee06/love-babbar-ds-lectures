#include <iostream>
#include "circular_linked_list.cpp"
using namespace std;

CList* split(Node* head, int size){
	Node* n1 = head;
	for (register int i=0; i<size/2; i++){
		n1 = n1->next;
	}
	Node* n2 = n1->next;
	CList* sl = new CList;
	while (n2!=head){
		sl->insert(n2->data);
		n2 = n2->next;
	}
	Node* prev = n1->next;
	Node* curr = prev->next;
	while (prev!=head){
		delete prev;
		prev = curr;
		curr = curr->next;
	}
	n1->next = head;

	return sl;
}

int main()
{
	CList l;
	int n, temp;
	cout<<"How many elements you want to enter : ";
	for (register int i=0; i<n; i++){
		cin>>temp;
		l.insert(temp);
	}
	CList* sl = split(l.getHead(),n);
	cout<<"First sub list\n";
	l.print();
	cout<<"Second sub list\n";
	sl->print();

	return 0;
}