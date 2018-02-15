#include "InsertNodeInSortedLinkedList.h"

InsertNodeInSortedLinkedList::InsertNodeInSortedLinkedList() {

	head = new node(2, nullptr);
	head->next = new node(5, nullptr);
	head->next->next = new node(7, nullptr);
	head->next->next->next = new node(10, nullptr);
	head->next->next->next->next = new node(15, nullptr);
}



InsertNodeInSortedLinkedList::~InsertNodeInSortedLinkedList() {
	link t = head;
	link g = nullptr;
	while (t != nullptr) {
		g = t;
		t = t->next;
		delete g;
	}
}


void InsertNodeInSortedLinkedList::insertR(link h, int val) {

	if (!h || val <= h->value) {
		head = new node(val, head);
		return;
	}

	while (h->next && val > h->next->value) h = h->next;
	h->next = new node(val, h->next);
}

std::ostream& operator<<(std::ostream& os, const InsertNodeInSortedLinkedList& list) {

	InsertNodeInSortedLinkedList::link t = list.head;
	while (t != nullptr) {
		os << t->value;
		t = t->next;
	}
	return os;
}