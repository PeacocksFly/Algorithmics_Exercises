#pragma once

//Given a linked list, write a function to reverse every k nodes(where k is an input to the function).
//
//Example:
//Inputs:  1->2->3->4->5->6->7->8->NULL and k = 3
//	Output : 3->2->1->6->5->4->8->7->NULL.
//
//	Inputs : 1->2->3->4->5->6->7->8->NULL and k = 5
//	Output : 5->4->3->2->1->8->7->6->NULL.

#include <iostream>

class ReverseLinkedListInGroupsOfGivenSize {

private:
	struct node {
		node* next;
		int value;
		node(int _value, node* _next) :
			value(_value),
			next(_next) {}
	};

	typedef node* link;
	link _head;

public:
	ReverseLinkedListInGroupsOfGivenSize() : _head(nullptr) {}
	~ReverseLinkedListInGroupsOfGivenSize();
	void insert(int _value) { _head = new node(_value, _head); };
	void reverseNR(int);
	friend std::ostream& operator<<(std::ostream&, const ReverseLinkedListInGroupsOfGivenSize&);
};
