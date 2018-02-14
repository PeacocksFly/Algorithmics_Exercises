#include "DetectAndRemoveLoopInALinkedList.h"

DetectAndRemoveLoopInALinkedList::DetectAndRemoveLoopInALinkedList() {

	head = new node(1, nullptr);
	head->next = new node(2, nullptr);
	head->next->next = new node(3, nullptr);
	head->next->next->next = new node(4, nullptr);
	head->next->next->next->next = new node(5, nullptr);
	head->next->next->next->next->next = head->next->next;

}



DetectAndRemoveLoopInALinkedList::~DetectAndRemoveLoopInALinkedList() {
	link t = head;
	link g = nullptr;
	while (t != nullptr) {
		g = t;
		t = t->next;
		delete g;
	}
}

void DetectAndRemoveLoopInALinkedList::detectAndRemoveLoopR(link h) {

	if (h == nullptr) return;
	std::vector<link> pastLinks = { h };
	while (h->next != nullptr) {
		if (std::find(pastLinks.begin(), pastLinks.end(), h->next) != pastLinks.end()) {
			h->next = nullptr;
			return;
		}
		else {
			pastLinks.push_back(h->next);
			h = h->next;
		}			
	}
}

std::ostream& operator<<(std::ostream& os, const DetectAndRemoveLoopInALinkedList& list) {

	DetectAndRemoveLoopInALinkedList::link t = list.head;
	while (t != nullptr) {
		os << t->value ;
		t = t->next;
	}
	return os;
}