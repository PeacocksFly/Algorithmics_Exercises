//Given two numbers represented by two linked lists, write a function that returns sum list.
//The sum list is linked list representation of addition of two input numbers.
//The input list can be used as solution storage
//
//Example
//
//Input :
//First List : 5->6->3  // represents number 563
//Second List : 8->4->2 //  represents number 842
//Output
//Resultant list : 1->4->0->5  // represents number 1405




#pragma once
#include <iostream>
#include <cmath>

class AddTwoNumbersRepresentedByLinkedList {

private:
	struct node {
		int _value;
		node* _next;

		node(int value,node* next):
			_value(value),
		    _next(next){}

	};

	typedef node* link;
	link _head;
	int _size;
	friend int sumR(link, link);
	friend int reportAddingR(link, link, int);
	friend void pickLongestList(link&, link&, int);



public:
	AddTwoNumbersRepresentedByLinkedList() :_head(nullptr) {}
	~AddTwoNumbersRepresentedByLinkedList();
	void insert(int value) { 
		_head = new node(value, _head);
		_size++;
	}

	friend void sum(AddTwoNumbersRepresentedByLinkedList& a, AddTwoNumbersRepresentedByLinkedList& b);
	friend std::ostream&  operator<<(std::ostream&, const AddTwoNumbersRepresentedByLinkedList&);
};
