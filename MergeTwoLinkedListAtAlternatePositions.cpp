#include "MergeTwoLinkedListAtAlternatePositions.h"


MergeTwoLinkedListAtAlternatePositions::~MergeTwoLinkedListAtAlternatePositions() {
	link t = head;
	link g = nullptr;
	while (t != nullptr) {
		g = t;
		t = t->next;
		delete g;
	}
}


void mergeAlternateListR(MergeTwoLinkedListAtAlternatePositions::link first, MergeTwoLinkedListAtAlternatePositions::link& second) {


	MergeTwoLinkedListAtAlternatePositions::link t = nullptr; 
	while (first && second) {
		t = second->next;
		second->next = first->next;
		first->next = second;
		second = t;
		first = first->next->next;
	}
}

std::ostream& operator<<(std::ostream& os, const  MergeTwoLinkedListAtAlternatePositions& list) {

	MergeTwoLinkedListAtAlternatePositions::link t = list.head;
	while (t != nullptr) {
		os << t->value;
		t = t->next;
	}
	return os;
}