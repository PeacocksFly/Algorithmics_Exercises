#include "QuicksortOnDoublyLinkedList.h"


QuicksortOnDoublyLinkedList::~QuicksortOnDoublyLinkedList() {
	link t = head;
	link g = nullptr;
	while (t != nullptr) {
		g = t;
		t = t->next;
		delete g;
	}
}

void QuicksortOnDoublyLinkedList::insert(int _value){
	
	if (head == nullptr) {
		head = new node(_value, nullptr, nullptr);
		tail = head;
		return;
	}

	head = new node(_value, head, nullptr);
	head->next->prev = head;
}

void QuicksortOnDoublyLinkedList::swap(link a, link b) {
	int temp = a->value;
	a->value = b->value;
	b->value = temp;
}

void  QuicksortOnDoublyLinkedList::sortR(link i, link j) {

	if (i == j) return;

	link pivot = j;
	link start = i;

	j = j->prev;
	for (;;) {

		while (i->value < pivot->value)  i = i->next;
		while (j->value > pivot->value) {
			if (j == start) break;
			j = j->prev;			
		}
		if ((i == j) || (j == i->prev))  break; 
		swap(i, j);
	}

	swap(i, pivot);
	if(i->prev !=nullptr)  sortR(start, i->prev);
	if(i->next !=nullptr)  sortR(i->next, pivot);
}


std::ostream& operator<<(std::ostream& os, const QuicksortOnDoublyLinkedList& list) {

	QuicksortOnDoublyLinkedList::link t = list.head;
	while (t != nullptr) {
		os << t->value << " ";
		t = t->next;
	}
	return os;
}