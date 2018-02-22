#include "AddTwoNumbersRepresentedByLinkedList.h"



AddTwoNumbersRepresentedByLinkedList::~AddTwoNumbersRepresentedByLinkedList() {

	link t = _head, g;
	while (t != nullptr) {
		g = t;
		t = t->_next;
		delete g;
	}
	_head = nullptr;
}

int sumR(AddTwoNumbersRepresentedByLinkedList::link a, AddTwoNumbersRepresentedByLinkedList::link b) {

	if (!a && !b) return 0;

	int report = sumR(a->_next, b->_next);

	int sum = a->_value + b->_value + report;
	report = sum / 10;
	a->_value =  sum % 10;
	return  report;

}

int reportAddingR(AddTwoNumbersRepresentedByLinkedList::link a, AddTwoNumbersRepresentedByLinkedList::link t, int report) {

	if (a == t) return report;

	int newReport = reportAddingR(a->_next, t, report);
	 
	int sum = a->_value + newReport;
	newReport = sum / 10;
	a->_value = sum % 10;
	return newReport;
}



void pickLongestList(AddTwoNumbersRepresentedByLinkedList::link& a, AddTwoNumbersRepresentedByLinkedList::link& b, int sizeDiff) {

	AddTwoNumbersRepresentedByLinkedList::link t = nullptr;
	int report = 0;
	t = a;
	while (sizeDiff-- > 0)
		t = t->_next;
	report = sumR(t, b);

	if (report == 0)
		return;
	else {
		int newReport = reportAddingR(a, t, report);
		if (newReport != 0)
			a = new AddTwoNumbersRepresentedByLinkedList::node(newReport, a);
	}
}


void sum(AddTwoNumbersRepresentedByLinkedList& a, AddTwoNumbersRepresentedByLinkedList& b) {
	
	if (!a._head || !b._head) return;
	
	int sizeDiff =  std::abs(a._size - b._size);
	if (a._size >= b._size) 
		pickLongestList(a._head, b._head, sizeDiff);
	else
		pickLongestList(b._head, a._head, sizeDiff);
		
}


std::ostream& operator<<(std::ostream& os, const AddTwoNumbersRepresentedByLinkedList& list) {

	AddTwoNumbersRepresentedByLinkedList::link t = list._head;
	while (t != nullptr) {
		os << t->_value << " ";
		t = t->_next;
	}
	return os;
}