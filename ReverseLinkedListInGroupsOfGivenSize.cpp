#include "ReverseLinkedListInGroupsOfGivenSize.h"

ReverseLinkedListInGroupsOfGivenSize::~ReverseLinkedListInGroupsOfGivenSize() {
	link t = _head;
	link g = nullptr;
	while (t != nullptr) {
		g = t;
		t = t->next;
		delete g;
	}
}


void ReverseLinkedListInGroupsOfGivenSize::reverseNR(int k) {
	
	link s = _head; 
	if (!s) return;

	link g = s;
	link sPrev = s;
	link i = nullptr;
	link j = nullptr;
	int kCopy = k;
	int a = 0;

	do {
		i = g->next;
		while (--k > 0 && i) {
			j = i->next;
			i->next = g;
			g = i;
			i = j;
		}
		if (a == 0) {
			_head = g;
			a++;
		}
		else {
			sPrev->next = g;
		}
		s->next = i;
		sPrev = s;
		s = i;
		g = i;
		k = kCopy;
		
	} while (s);
}

std::ostream& operator<<(std::ostream& os, const ReverseLinkedListInGroupsOfGivenSize& list) {

	ReverseLinkedListInGroupsOfGivenSize::link t = list._head;
	while (t != nullptr) {
		os << t->value;
		t = t->next;
	}
	return os;
}


