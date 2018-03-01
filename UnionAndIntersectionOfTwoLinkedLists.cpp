#include "UnionAndIntersectionOfTwoLinkedLists.h"

UnionAndIntersectionOfTwoLinkedLists::UnionAndIntersectionOfTwoLinkedLists() {}


UnionAndIntersectionOfTwoLinkedLists::~UnionAndIntersectionOfTwoLinkedLists() {
	link t = _head;
	link g = nullptr;
	while (t != nullptr) {
		g = t;
		t = t->next;
		delete g;
	}
}


void UnionAndIntersectionOfTwoLinkedLists::unionAndIntersectionP(link& a, link& b) {

	//union list result in a
	//intersection list result in b
	//assumption: no duplicates in initial lists
	if (!a) { a = b; b = nullptr; return; }
	if (!b) return;

	std::vector<int> tab(100); //considering maxNumber in linked list is 99
	
	link t = a;
	while (true) { 
		tab[t->value] = 1;
		if (t->next) t = t->next;
		else break;
	}

	link f = b;
	link intersectStart = new node(-1, nullptr);
	link startB = intersectStart;
	link g = nullptr;
	while (f) {
		if (tab[f->value] == 1) { g = f->next; intersectStart->next = f; intersectStart = f; intersectStart->next = nullptr; f = g; }		
		else { t->next = f;  t = f;  f = f->next;  t->next = nullptr; }
	}
	b = startB->next;
}



std::ostream& operator<<(std::ostream& os, const UnionAndIntersectionOfTwoLinkedLists& list) {

	UnionAndIntersectionOfTwoLinkedLists::link t = list._head;
	while (t != nullptr) {
		os << t->value;
		t = t->next;
	}
	return os;
}