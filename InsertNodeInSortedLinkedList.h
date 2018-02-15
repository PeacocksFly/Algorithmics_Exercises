#pragma once

//Given a sorted linked list and a value to insert, write a function to insert the value in sorted way.

#include <iostream>

class InsertNodeInSortedLinkedList {

private:
	struct node {
		node* next;
		int value;
		node(int _value, node* _next) :
			value(_value),
			next(_next) {}
	};

	typedef node* link;
	link head;
	void insertR(link, int);

public:
	InsertNodeInSortedLinkedList();
	~InsertNodeInSortedLinkedList();
	void insert(int _value) { insertR(head, _value); };
	friend std::ostream& operator<<(std::ostream&, const InsertNodeInSortedLinkedList&);
};
