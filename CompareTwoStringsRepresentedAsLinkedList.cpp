#include"CompareTwoStringsRepresentedAsLinkedList.h"

CompareTwoStringsRepresentedAsLinkedList::~CompareTwoStringsRepresentedAsLinkedList() {
	link t = head;
	link g = nullptr;
	while (t!=nullptr) {
		g = t;
		t = t->next;
		delete g;
	}
}

int compare(const CompareTwoStringsRepresentedAsLinkedList& str1, const CompareTwoStringsRepresentedAsLinkedList& str2) {

	CompareTwoStringsRepresentedAsLinkedList::link t1 = str1.head;
	CompareTwoStringsRepresentedAsLinkedList::link t2 = str2.head;

	while ((t1 != nullptr && t2 != nullptr) && (t1->value == t2->value)) {
		t1 = t1->next;
		t2 = t2->next;
	}

	if (t1 == nullptr && t2 == nullptr) return 0;
	if (t1 == nullptr || t2 == nullptr)
		return (t1 == nullptr) ? -1 : 1;
	return  (t1->value < t2->value) ? -1 : 1;
}